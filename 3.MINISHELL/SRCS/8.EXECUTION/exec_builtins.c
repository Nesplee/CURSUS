/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:01:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 13:47:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	EXECUTE_BUILTIN - Exécute une commande builtin.
** ============================================================================
**	Parametres:
**		- @cmd:   pointeur vers t_command décrivant la commande.
**		- @shell: pointeur vers le contexte global du shell.
**		- @env:   tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. Selon cmd->builtin_id, appeler la fonction correspondante.
**		2. Transmettre les arguments et le contexte approprié.
**
**	Retour:
**		Code de retour du builtin (EXIT_SUCCESS ou EXIT_FAILURE).
*/
static int	execute_builtin(t_command *cmd, t_shell *shell, char **env)
{
	if (cmd->builtin_id == BI_ECHO)
		return (ft_echo(cmd->args));
	else if (cmd->builtin_id == BI_CD)
		return (ft_cd(cmd->args, env));
	else if (cmd->builtin_id == BI_PWD)
		return (ft_pwd());
	else if (cmd->builtin_id == BI_EXPORT)
		return (ft_export(cmd->args, &shell->env));
	else if (cmd->builtin_id == BI_UNSET)
		return (ft_unset(cmd->args, &shell->env));
	else if (cmd->builtin_id == BI_ENV)
		return (ft_env(env));
	else if (cmd->builtin_id == BI_EXIT)
		return (ft_exit(shell, cmd->args));
	return (EXIT_FAILURE);
}

/*
** ============================================================================
**	APPLY_REDIRS_BUILTIN - Applique les redirections pour un builtin.
** ============================================================================
**	Parametres:
**		- @cmd:           pointeur vers t_command contenant redirs[].
**		- @backup_stdout: adresse pour stocker copie de STDOUT.
**		- @backup_stdin:  adresse pour stocker copie de STDIN.
**
**	Variables locales:
**		- ret_setup: code de retour de setup_redirections().
**
**	Processus:
**		1. Dupliquer STDOUT et STDIN dans backup_stdout/backup_stdin.
**		2. Appeler setup_redirections(cmd).
**		3. Si échec, restaurer descripteurs et retourner EXIT_FAILURE.
**
**	Retour:
**		EXIT_SUCCESS si redirections appliquées, EXIT_FAILURE sinon.
*/
static int	apply_redirs_builtin(t_command *cmd, int *backup_stdout,
		int *backup_stdin, t_shell *shell)
{
	int	ret_setup;

	*backup_stdout = dup(STDOUT_FILENO);
	*backup_stdin = dup(STDIN_FILENO);
	ret_setup = setup_redirections(cmd, shell);
	if (ret_setup == 0)
	{
		if (*backup_stdout != -1)
		{
			dup2(*backup_stdout, STDOUT_FILENO);
			close(*backup_stdout);
		}
		if (*backup_stdin != -1)
		{
			dup2(*backup_stdin, STDIN_FILENO);
			close(*backup_stdin);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/*
** ============================================================================
**	RESTORE_STD_DESCRIPTORS - Restaure STDIN et STDOUT après redirections.
** ============================================================================
**	Parametres:
**		- @backup_stdout: copie de STDOUT à restaurer.
**		- @backup_stdin:  copie de STDIN à restaurer.
**
**	Processus:
**		1. Si backup_stdout valide, dup2() puis close().
**		2. Si backup_stdin valide, dup2() puis close().
**
**	Retour:
**		(void)
*/

static void	restore_std_descriptors(int backup_stdout, int backup_stdin)
{
	if (backup_stdout != -1)
	{
		dup2(backup_stdout, STDOUT_FILENO);
		close(backup_stdout);
	}
	if (backup_stdin != -1)
	{
		dup2(backup_stdin, STDIN_FILENO);
		close(backup_stdin);
	}
}

/*
** ============================================================================
**	EXECUTE_BUILTIN_WITH_REDIR - Exécute un builtin avec gestion des redirs.
** ============================================================================
**	Parametres:
**		- @cmd:   pointeur vers t_command à exécuter.
**		- @shell: pointeur vers le contexte global du shell.
**		- @env:   tableau d'environnement "KEY=VALUE".
**
**	Variables locales:
**		- backup_stdout, backup_stdin: descripteurs sauvegardés.
**		- redir_result: code de apply_redirs_builtin().
**		- ret: code de retour du builtin exécuté.
**
**	Processus:
**		1. Appeler apply_redirs_builtin(); si EXIT_FAILURE, retourner
**										EXIT_FAILURE.
**		2. Exécuter execute_builtin().
**		3. Restaurer STDOUT/STDIN via restore_std_descriptors().
**
**	Retour:
**		Code de retour du builtin ou EXIT_FAILURE en cas d’erreur.
*/
int	execute_builtin_with_redir(t_command *cmd, t_shell *shell, char **env)
{
	int	backup_stdout;
	int	backup_stdin;
	int	redir_result;
	int	ret;

	backup_stdout = -1;
	backup_stdin = -1;
	redir_result = apply_redirs_builtin(cmd, &backup_stdout,
			&backup_stdin, shell);
	if (redir_result == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ret = execute_builtin(cmd, shell, env);
	restore_std_descriptors(backup_stdout, backup_stdin);
	return (ret);
}
