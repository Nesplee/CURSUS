/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_logicals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:23:33 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:18:56 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	COUNT_LOGICALS - Compte les opérateurs logiques hors parenthèses.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* issu du lexer.
**
**	Variables locales:
**		i:     index courant dans tokens[].
**		count: nombre d'opérateurs logiques comptés.
**		depth: profondeur dans les parenthèses.
**
**	Processus:
**		1. Initialiser i = 0, count = 0, depth = 0.
**		2. Parcourir tokens[i] tant que non NULL.
**		   a. Si '(' ou ')', ajuster depth.
**		   b. Si && ou || et depth == 0, incrémenter count.
**		3. Retourner count.
**
**	Retour:
**		Nombre d'opérateurs logiques extérieurs aux groupes.
*/
int	count_logicals(t_token **tokens)
{
	int	i;
	int	count;
	int	depth;

	i = 0;
	count = 0;
	depth = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == T_OPERATOR)
		{
			if (tokens[i]->ope == OP_LPAR)
				depth++;
			else if (tokens[i]->ope == OP_RPAR)
				depth--;
			else if ((tokens[i]->ope == OP_AND || tokens[i]->ope == OP_OR)
				&& depth == 0)
				count++;
		}
		i++;
	}
	return (count);
}

/*
** ============================================================================
**	FILL_LOGICALS - Remplit le tableau de commandes par segments.
** ============================================================================
**	Parametres:
**		- @parser:        pointeur sur t_parser avec tokens et current.
**		- @commands:      tableau de t_command* à remplir.
**		- @logical_count: nombre d'opérateurs logiques à traiter.
**		- @ops:           tableau de t_operator_type pour stocker ops.
**
**	Variables locales:
**		i: index du segment courant.
**
**	Processus:
**		1. Boucler i de 0 à logical_count inclus.
**		2. commands[i] = parse_group_or_command(parser).
**		3. Si NULL, retourner i (erreur).
**		4. Si i < logical_count :
**		   a. Vérifier token courant est OP_AND ou OP_OR.
**		   b. ops[i] = token->ope ; parser->current++.
**		   c. Sinon retourner i.
**		5. Incrémenter i.
**		6. Après boucle, placer commands[i] = NULL.
**
**	Retour:
**		-1 si succès complet, sinon indice du segment en erreur.
*/
static int	fill_logicals(t_parser *parser, t_command **commands,
	int logical_count, t_operator_type *ops)
{
	int	i;

	i = 0;
	while (i <= logical_count)
	{
		commands[i] = parse_group_or_command(parser);
		if (!commands[i])
			return (i);
		if (i < logical_count)
		{
			if (parser->tokens[parser->current]->type == T_OPERATOR
				&& (parser->tokens[parser->current]->ope == OP_AND
					|| parser->tokens[parser->current]->ope == OP_OR))
			{
				ops[i] = parser->tokens[parser->current]->ope;
				parser->current++;
			}
			else
				return (i);
		}
		i++;
	}
	commands[i] = NULL;
	return (-1);
}

/*
** ============================================================================
**	PARSE_LOGICALS - Point d'entrée du parsing logique.
** ============================================================================
**	Parametres:
**		- @parser:        pointeur sur t_parser contenant les tokens.
**		- @logical_count: nombre d'opérateurs logiques hors groupes.
**
**	Variables locales:
**		- commands: tableau de t_command* retourné.
**		- ops:      tableau de t_operator_type alloué.
**		- ret:      code retour de fill_logicals().
**
**	Processus:
**		1. parser->cmd_count = logical_count + 1.
**		2. Allouer commands de taille cmd_count + 1.
**		3. Allouer ops de taille logical_count.
**		4. Si allocation échoue, libérer et cleanup_parser().
**		5. ret = fill_logicals(...).
**		6. Si ret != -1, libérer ressources et cleanup_parser().
**		7. commands[cmd_count] = NULL.
**		8. commands[0]->sub_ops = ops.
**		9. commands[0]->sub_op_count = logical_count.
**
**	Retour:
**		Tableau de commandes ou NULL si erreur.
*/
t_command	**parse_logicals(t_parser *parser, int logical_count)
{
	t_command		**commands;
	t_operator_type	*ops;
	int				ret;

	parser->cmd_count = logical_count + 1;
	commands = malloc(sizeof(*commands) * (parser->cmd_count + 1));
	ops = malloc(sizeof(*ops) * logical_count);
	if (!commands || (logical_count && !ops))
		return (dis_memory_err(), cleanup_parser(parser));
	ret = fill_logicals(parser, commands, logical_count, ops);
	if (ret != -1)
	{
		free_command_list(commands);
		free(ops);
		return (cleanup_parser(parser));
	}
	commands[parser->cmd_count] = NULL;
	commands[0]->sub_ops = ops;
	commands[0]->sub_op_count = logical_count;
	return (commands);
}
