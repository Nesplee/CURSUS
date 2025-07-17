/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshells.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:24:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:05:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	EXECUTE_SUBSHELL - Exécute un groupe de commandes dans un sous-shell.
** ============================================================================
**	Parametres:
**		- @cmd:   pointeur vers t_command contenant sub_commands[] et sub_ops[]
**		- @shell: pointeur vers t_shell pour le contexte global.
**		- @env:   tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. Initialiser rc = EXIT_SUCCESS et i = 0.
**		2. Tant que cmd->sub_commands[i] non NULL :
**		   a. rc = execute_command(sub_commands[i], shell, env).
**		   b. Si i < sub_op_count :
**		      - Si sub_ops[i] == OP_AND et rc != EXIT_SUCCESS, break.
**		      - Si sub_ops[i] == OP_OR  et rc == EXIT_SUCCESS, break.
**		   c. i++.
**		3. Retourner rc.
**
**	Retour:
**		Code de retour final du sous-shell.
*/
int	execute_subshell(t_command *cmd, t_shell *shell, char **env)
{
	int	i;
	int	rc;

	i = 0;
	rc = EXIT_SUCCESS;
	while (cmd->sub_commands[i])
	{
		rc = execute_command(cmd->sub_commands[i], shell, env);
		if (i < cmd->sub_op_count)
		{
			if (cmd->sub_ops[i] == OP_AND && rc != EXIT_SUCCESS)
				break ;
			if (cmd->sub_ops[i] == OP_OR && rc == EXIT_SUCCESS)
				break ;
		}
		i++;
	}
	return (rc);
}
