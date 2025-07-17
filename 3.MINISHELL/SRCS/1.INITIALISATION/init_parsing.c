/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:59:45 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 18:29:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			INIT_COMMAND - Alloue et initialise une commande vide.
** ============================================================================
**	Parametres:
**		(aucun)
**
**	Variables locales :
**		command - pointeur sur t_command alloué.
**
**	Processus :
**		1. Allouer la structure t_command.
**		2. Mettre tous les octets à 0 via ft_memset().
**		3. Initialiser pipe_fd[0] et pipe_fd[1] à -1.
**		4. Initialiser sub_commands et sub_ops à NULL.
**		5. Initialiser sub_op_count et is_subshell à 0.
**
**	Retour :
**		Pointeur sur t_command si succès, NULL sinon.
*/
t_command	*init_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	ft_memset(command, 0, sizeof(t_command));
	command->pipe_fd[0] = -1;
	command->pipe_fd[1] = -1;
	command->sub_commands = NULL;
	command->sub_ops = NULL;
	command->sub_op_count = 0;
	command->is_subshell = 0;
	return (command);
}

/*
** ============================================================================
**			INIT_PARSER - Alloue et initialise le parser.
** ============================================================================
**	Parametres:
**		(aucun)
**
**	Variables locales :
**		parser  - pointeur sur t_parser alloué.
**
**	Processus :
**		1. Allouer la structure t_parser.
**		2. Initialiser tokens à NULL.
**		3. Initialiser current et cmd_count à 0.
**		4. Initialiser commands à NULL.
**
**	Retour :
**		Pointeur sur t_parser si succès, NULL sinon.
*/
t_parser	*init_parser(void)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->tokens = NULL;
	parser->current = 0;
	parser->commands = NULL;
	parser->cmd_count = 0;
	return (parser);
}
