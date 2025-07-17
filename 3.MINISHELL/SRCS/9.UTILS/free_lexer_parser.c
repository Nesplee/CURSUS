/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:39:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:10:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	FREE_LEXER - Libère un lexer et tous ses tokens.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer à libérer.
**
**	Processus:
**		1. Si lexer NULL, return.
**		2. Si lexer->input non NULL, free(lexer->input).
**		3. Si lexer->tokens non NULL :
**		   a. Pour i de 0 à lexer->token_count - 1 :
**		      - Si lexer->tokens[i] non NULL, free_token(lexer->tokens[i]).
**		   b. free(lexer->tokens).
**		4. free(lexer).
**
**	Retour:
**		(void)
*/
void	free_lexer(t_lexer *lexer)
{
	int	i;

	if (lexer)
	{
		if (lexer->input)
			free(lexer->input);
		if (lexer->tokens)
		{
			i = 0;
			while (i < lexer->token_count)
			{
				if (lexer->tokens[i])
					free_token(lexer->tokens[i]);
				i++;
			}
			free(lexer->tokens);
		}
		free(lexer);
	}
}

/*
** ============================================================================
**	FREE_PARSER - Libère un parser et toutes ses commandes.
** ============================================================================
**	Parametres:
**		- @parser: pointeur vers t_parser à libérer.
**
**	Processus:
**		1. Si parser NULL, return.
**		2. Si parser->commands non NULL :
**		   a. Pour i de 0 à parser->cmd_count - 1 :
**		      - free_command(parser->commands[i]).
**		   b. free(parser->commands).
**		3. free(parser).
**
**	Retour:
**		(void)
*/
void	free_parser(t_parser *parser)
{
	int	i;

	if (parser)
	{
		if (parser->commands)
		{
			i = 0;
			while (i < parser->cmd_count)
				free_command(parser->commands[i++]);
			free(parser->commands);
		}
		free(parser);
	}
}
