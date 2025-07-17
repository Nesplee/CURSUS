/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:19:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 18:32:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			CREATE_OPERATOR_TOKEN - Crée un token opérateur.
** ============================================================================
**	Parametres:
**		- @lexer: structure du lexer en cours d'analyse.
**		- @type:  type d'opérateur (OP_AND, OP_OR, ...).
**		- @value: chaîne C représentant l'opérateur.
**		- @advance: nombre de caractères à avancer.
**
**	Variables locales :
**		token: pointeur vers le nouveau token alloué.
**
**	Processus :
**		1. Allouer un token via init_token().
**		2. Initialiser type, ope et cloner value avec ft_strdup().
**		3. En cas d'erreur, libérer token et retourner 0.
**		4. Avancer lexer->position de advance.
**		5. Appeler add_token() pour l'insertion.
**
**	Retour :
**		1 si succès, 0 sinon.
*/
static int	create_operator_token(t_lexer *lexer, t_operator_type type,
	char *value, int advance)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (0);
	token->type = T_OPERATOR;
	token->ope = type;
	token->value = ft_strdup(value);
	if (!token->value)
	{
		free_token(token);
		return (0);
	}
	lexer->position += advance;
	add_token(lexer, token);
	return (1);
}

/*
** ============================================================================
**			HANDLE_OPERATOR - Analyse et crée le token opérateur.
** ============================================================================
**	Parametres:
**		- @lexer: structure du lexer en cours d'analyse.
**
**	Variables locales :
**		current, next: caractères à la position courante et suivante.
**
**	Processus :
**		1. Lire current et next.
**		2. Identifier la combinaison (||, &&, |, (, )).
**		3. Appeler create_operator_token() avec les bons args.
**
**	Retour :
**		1 si succès, 0 sinon.
*/
int	handle_operator(t_lexer *lexer)
{
	char	current;
	char	next;

	current = lexer->input[lexer->position];
	next = lexer->input[lexer->position + 1];
	if (current == '|' && next == '|')
		return (create_operator_token(lexer, OP_OR, "||", 2));
	else if (current == '&' && next == '&')
		return (create_operator_token(lexer, OP_AND, "&&", 2));
	else if (current == '|')
		return (create_operator_token(lexer, OP_PIPE, "|", 1));
	else if (current == '(')
		return (create_operator_token(lexer, OP_LPAR, "(", 1));
	return (create_operator_token(lexer, OP_RPAR, ")", 1));
}
