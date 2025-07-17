/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:29:01 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:11:25 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	FREE_ENV - Libère le tableau d'environnement et ses chaînes.
** ============================================================================
**	Parametres:
**		- @env: tableau de chaînes "KEY=VALUE".
**
**	Processus:
**		1. Si env NULL, return.
**		2. Pour chaque env[i] non NULL, free(env[i]).
**		3. free(env).
**
**	Retour:
**		(void)
*/
void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
			free(env[i++]);
		free(env);
	}
}

/*
** ============================================================================
**	FREE_SHELLITO - Libère les commandes stockées dans le shell.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell contenant commands[].
**
**	Processus:
**		1. Si shell NULL, return.
**		2. Si shell->commands non NULL :
**		   a. Pour chaque shell->commands[i], free_command().
**		   b. free(shell->commands).
**
**	Retour:
**		(void)
*/
static void	free_shellito(t_shell *shell)
{
	int	i;

	if (shell)
	{
		if (shell->commands)
		{
			i = 0;
			while (shell->commands[i])
				free_command(shell->commands[i++]);
			free(shell->commands);
		}
	}
}

/*
** ============================================================================
**	FREE_SHELL - Libère toutes les structures du shell.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell à libérer.
**
**	Processus:
**		1. Si shell NULL, return.
**		2. free_lexer(shell->lexer).
**		3. free_parser(shell->parser).
**		4. free_shellito(shell).
**		5. free_env(shell->env).
**		6. free(shell->cwd).
**		7. free(shell).
**
**	Retour:
**		(void)
*/
void	free_shell(t_shell *shell)
{
	if (shell)
	{
		free_lexer(shell->lexer);
		free_parser(shell->parser);
		free_shellito(shell);
		free_env(shell->env);
		free(shell->cwd);
		free(shell);
	}
}
