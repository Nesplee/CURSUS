/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:18:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:20:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	FREE_TOKEN - Libère un token et sa valeur.
** ============================================================================
**	Parametres:
**		- @token: pointeur vers t_token à libérer.
**
**	Processus:
**		1. Si token non NULL :
**		   a. Si token->value non NULL, free(token->value).
**		   b. free(token).
**
**	Retour:
**		(void)
*/
void	free_token(t_token *token)
{
	if (token)
	{
		if (token->value)
			free(token->value);
		free(token);
	}
}

/*
** ============================================================================
**	FREE_REDIR - Libère une redirection et son champ file.
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir à libérer.
**
**	Processus:
**		1. Si redir non NULL :
**		   a. free(redir->file).
**		   b. free(redir).
**
**	Retour:
**		(void)
*/
static void	free_redir(t_redir *redir)
{
	if (redir)
	{
		free(redir->file);
		free(redir);
	}
}

/*
** ============================================================================
**	FREE_COMMAND - Libère une commande et toutes ses sous-structures.
** ============================================================================
**	Parametres:
**		- @command: pointeur vers t_command à libérer.
**
**	Processus:
**		1. Si command NULL, return.
**		2. Libérer chaque redirection via free_redir(), puis
**					free(command->redirs).
**		3. free(command->name).
**		4. Si args non NULL, ft_split_free(command->args).
**		5. Si sub_commands non NULL, récursivement free_command()
**					puis free(sub_commands).
**		6. Si sub_ops non NULL, free(sub_ops).
**		7. free(command).
**
**	Retour:
**		(void)
*/
void	free_command(t_command *command)
{
	int	i;

	if (!command)
		return ;
	if (command->redirs)
	{
		i = 0;
		while (i < command->redir_count)
			free_redir(command->redirs[i++]);
		free(command->redirs);
	}
	free(command->name);
	if (command->args)
		ft_split_free(command->args);
	if (command->sub_commands)
	{
		i = 0;
		while (command->sub_commands[i])
			free_command(command->sub_commands[i++]);
		free(command->sub_commands);
	}
	if (command->sub_ops)
		free(command->sub_ops);
	free(command);
}

/*
** ============================================================================
**	FREE_COMMAND_LIST - Libère un tableau de commandes.
** ============================================================================
**	Parametres:
**		- @commands: tableau NULL-terminé de t_command*.
**
**	Processus:
**		1. Si commands NULL, return.
**		2. Parcourir et appeler free_command() pour chaque élément.
**		3. free(commands).
**
**	Retour:
**		(void)
*/
void	free_command_list(t_command **commands)
{
	int	i;

	if (!commands)
		return ;
	i = 0;
	while (commands[i])
	{
		free_command(commands[i]);
		i++;
	}
	free(commands);
}
