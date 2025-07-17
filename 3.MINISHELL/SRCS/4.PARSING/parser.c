/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:27:31 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	VALIDATE_PARSER - Vérifie la validité de la structure parser.
** ============================================================================
**	Parametres:
**		- @parser: pointeur vers t_parser.
**
**	Processus:
**		1. Vérifier parser et parser->tokens non-NULL.
**		2. Initialiser parser->current, parser->commands, parser->cmd_count.
**
**	Retour:
**		1 si valide, 0 sinon.
*/
static int	validate_parser(t_parser *parser)
{
	if (!parser || !parser->tokens)
		return (0);
	parser->current = 0;
	parser->commands = NULL;
	parser->cmd_count = 0;
	return (1);
}

/*
** ============================================================================
**	PROCESS_PARSER_LOGIC - Applique la logique de parsing.
** ============================================================================
**	Parametres:
**		- @prs: pointeur vers t_parser contenant tokens et index.
**
**	Processus:
**		1. Compter les opérateurs logiques via count_logicals().
**		2. Si count > 0, appeler parse_logicals().
**		3. Sinon, appeler parse_pipes().
**
**	Retour:
**		1 si prs->commands non NULL, 0 sinon.
*/
static int	process_parser_logic(t_parser *prs)
{
	int	log_c;

	log_c = count_logicals(prs->tokens);
	if (log_c > 0)
		prs->commands = parse_logicals(prs, log_c);
	else if (!parse_pipes(prs))
		return (0);
	return (prs->commands != NULL);
}

/*
** ============================================================================
**	PARSER - Point d'entrée principal du parser.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* générés par le lexer.
**
**	Processus:
**		1. Initialiser un t_parser via validate_parser().
**		2. Appeler process_parser_logic().
**		3. En cas d'erreur, libérer via cleanup_parser().
**		4. Retourner prs.commands.
**
**	Retour:
**		Tableau de commandes (t_command**) ou NULL en cas d’erreur.
*/
t_command	**parser(t_token **tokens)
{
	t_parser	prs;

	prs.tokens = tokens;
	if (!validate_parser(&prs) || !process_parser_logic(&prs))
		return (cleanup_parser(&prs));
	return (prs.commands);
}
