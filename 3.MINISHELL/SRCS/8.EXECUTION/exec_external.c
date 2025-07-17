/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:30:40 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:34:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	GET_VALID_EXEC_PATH - Détermine le chemin exécutable valide.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command contenant le nom de la commande.
**		- @env: tableau d'environnement "KEY=VALUE".
**
**	Variables locales:
**		- path: chemin retourné par find_executable().
**		- sb:   structure stat pour vérifier type et permissions.
**
**	Processus:
**		1. path = find_executable(cmd->name, env).
**		2. Si path NULL, afficher erreur et exit(127).
**		3. Si path est un répertoire, afficher erreur et exit(126).
**		4. Si pas exécutable (access X_OK), afficher erreur et exit(126).
**		5. Retourner path alloué.
*/
static char	*get_valid_exec_path(t_command *cmd, char **env)
{
	char		*path;
	struct stat	sb;

	path = find_executable(cmd->name, env);
	if (!path)
	{
		dis_cmd_not_found_err(cmd->name);
		exit(127);
	}
	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		dis_is_directory_err(path);
		free(path);
		exit(126);
	}
	if (access(path, X_OK) != 0)
	{
		dis_perm_err(path);
		free(path);
		exit(126);
	}
	return (path);
}

/*
** ============================================================================
**	EXECUTE_IN_CHILD - Lance la commande externe dans le processus fils.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command décrivant la commande.
**		- @env: tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. Restaurer les signaux SIGINT et SIGQUIT par défaut.
**		2. Obtenir path via get_valid_exec_path().
**		3. Appeler execve(path, cmd->args, env).
**		4. En cas d'échec, afficher erreur, free(path) et exit(127).
*/
static void	execute_in_child(t_command *cmd, char **env)
{
	char	*exec_path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	exec_path = get_valid_exec_path(cmd, env);
	execve(exec_path, cmd->args, env);
	dis_cmd_not_found_err(cmd->name);
	free(exec_path);
	exit(127);
}

/*
** ============================================================================
**	EXECUTE_EXTERNAL_COMMAND - Lance un processus pour une commande externe.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command de la commande à exécuter.
**		- @env: tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. fork() pour créer un fils.
**		2. Si fork échoue, perror("fork") et return EXIT_FAILURE.
**		3. Dans le fils, appeler execute_in_child().
**		4. Dans le parent, waitpid() et récupérer le status.
**		5. Si signalé, retourner 128 + numéro du signal.
**		6. Sinon, retourner code de sortie du fils.
**
**	Retour:
**		Code de retour de l'exécution (EXIT_SUCCESS ou code d'erreur).
*/

int	execute_external_command(t_command *cmd, char **env)
{
	pid_t	pid;
	int		status;

	if (cmd->name && cmd->name[0] == '\0')
	{
		dis_cmd_not_found_err(cmd->name);
		return (127);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
		execute_in_child(cmd, env);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}
