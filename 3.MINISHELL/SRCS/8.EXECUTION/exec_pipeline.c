/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:46:35 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 13:20:43 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	EXEC_CHILD - Duplication des descripteurs et exécution dans le fils.
** ============================================================================
**	Parametres:
**		- @cmd:     commande à exécuter.
**		- @prev_fd: descripteur d'entrée hérité du précédent pipe ou -1.
**		- @pipe_fd: tableau [read, write] du pipe courant ou NULL si dernier.
**		- @shell:   contexte global du shell.
**
**	Processus:
**		1. Si prev_fd >= 0, dupliquer prev_fd sur STDIN, fermer prev_fd.
**		2. Si pipe_fd non NULL, dupliquer pipe_fd[1] sur STDOUT,
**		   fermer pipe_fd[0] et pipe_fd[1].
**		3. Appeler execute_command() et exit() avec son code.
**
**	Retour:
**		(void) – termine par exit().
*/
static void	exec_child(t_command *cmd, int prev_fd,
					int *pipe_fd, t_shell *shell)
{
	if (prev_fd >= 0)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (pipe_fd)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	if (cmd->redir_count > 0 && !setup_redirections(cmd, shell))
		exit(EXIT_FAILURE);
	exit(execute_command(cmd, shell, shell->env));
}

/*
** ============================================================================
**	SPAWN_PROCESS - Création d’un processus pour chaque maillon du pipeline.
** ============================================================================
**	Parametres:
**		- @cmd:     commande à lancer.
**		- @prev_fd: descripteur d’entrée du pipe précédent.
**		- @pipe_fd: tableau [read, write] pour le nouveau pipe ou NULL.
**		- @shell:   contexte global du shell.
**
**	Processus:
**		1. fork(). En erreur, afficher via dis_fork_err() et retourner -1.
**		2. Dans le fils (pid == 0) :
**		   a. Si cmd->redir_count > 0, appeler setup_redirections(), exit si
**				 échec.
**		   b. Appeler exec_child().
**		3. Dans le parent, retourner pid du fils.
**
**	Retour:
**		PID du fils (>0), 0 si fils, ou -1 en erreur.
*/
static pid_t	spawn_process(t_command *cmd, int prev_fd,
					int *pipe_fd, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		dis_fork_err();
		return (-1);
	}
	if (pid == 0)
		exec_child(cmd, prev_fd, pipe_fd, shell);
	return (pid);
}

/*
** ============================================================================
**	PROCESS_COMMAND_ITERATION - Prépare pipe et lance chaque commande.
** ============================================================================
**	Parametres:
**		- @idx:     index de la commande dans cmds[].
**		- @cmds:    tableau de commandes du pipeline.
**		- @prev_fd: adresse du descripteur d’entrée du pipe précédent.
**		- @shell:   contexte global du shell.
**
**	Processus:
**		1. Si cmds[idx+1] existe, créer un nouveau pipe.
**		2. Appeler spawn_process() pour forker et exécuter la commande.
**		3. Fermer l’ancien prev_fd si valide.
**		4. Si pipe créé, fermer son côté write et stocker read dans *prev_fd.
**
**	Retour:
**		0 si succès, -1 en cas d’erreur de pipe ou fork.
*/
int	process_command_iteration(int idx, t_command **cmds,
	int *prev_fd, t_shell *shell)
{
	int		pipe_fd[2];
	int		ret;
	int		*child_pipe;
	pid_t	pid;

	child_pipe = NULL;
	if (cmds[idx + 1])
	{
		ret = pipe(pipe_fd);
		if (ret < 0)
			return (-1);
		child_pipe = pipe_fd;
	}
	pid = spawn_process(cmds[idx], *prev_fd, child_pipe, shell);
	if (pid < 0)
		return (-1);
	if (*prev_fd >= 0)
		close(*prev_fd);
	if (cmds[idx + 1])
	{
		close(pipe_fd[1]);
		*prev_fd = pipe_fd[0];
	}
	return (0);
}

/*
** ============================================================================
**	HANDLE_PARENT_BUILTIN - Exécute un builtin en parent si pipeline simple.
** ============================================================================
**	Parametres:
**		- @cmds:  tableau de commandes.
**		- @shell: contexte global du shell.
**		- @env:   environnement pour le builtin.
**
**	Processus:
**		1. Si une seule commande et c’est un builtin modifiant l’état:
**		   cd, export, unset ou exit,
**		   exécuter avec execute_builtin_with_redir() et retourner son code.
**		2. Sinon, retourner -1 pour prise en charge normale.
**
**	Retour:
**		Code du builtin ou -1 si non traité ici.
*/
static int	handle_parent_builtin(t_command **cmds, t_shell *shell, char **env)
{
	int	ret;

	if (cmds[0] && cmds[1] == NULL
		&& cmds[0]->is_builtin
		&& (cmds[0]->builtin_id == BI_CD
			|| cmds[0]->builtin_id == BI_EXPORT
			|| cmds[0]->builtin_id == BI_UNSET
			|| cmds[0]->builtin_id == BI_EXIT))
	{
		ret = execute_builtin_with_redir(cmds[0], shell, env);
		shell->exit_status = ret;
		return (ret);
	}
	return (-1);
}

/*
** ============================================================================
**	EXECUTE_COMMANDS - Lance l’enchaînement de commandes en pipeline.
** ============================================================================
**	Parametres:
**		- @cmds:  tableau de commandes à exécuter.
**		- @shell: contexte global du shell.
**		- @env:   environnement "KEY=VALUE".
**
**	Processus:
**		1. Tenter handle_parent_builtin() ; si != -1, retourner directement.
**		2. Initialiser idx=0, prev_fd=-1.
**		3. Pour chaque commande cmds[idx]:
**		   a. process_command_iteration().
**		   b. En cas d’erreur, afficher via dis_pipe_err(), retourner
**				EXIT_FAILURE.
**		4. Attendre tous les fils.
**		5. Si dernier statut signalisé, retourner 128+signal.
**		6. Sinon, retourner WEXITSTATUS.
**
**	Retour:
**		Code de retour global du pipeline.
*/

int	execute_commands(t_command **cmds, t_shell *shell, char **envp)
{
	int	ret;

	ret = handle_parent_builtin(cmds, shell, envp);
	if (ret != -1)
		return (ret);
	if (!process_heredocs(cmds, shell, envp))
		return (shell->exit_status);
	if (!spawn_pipeline(cmds, shell))
		return (shell->exit_status);
	shell->exit_status = collect_exit_status(shell);
	return (shell->exit_status);
}
