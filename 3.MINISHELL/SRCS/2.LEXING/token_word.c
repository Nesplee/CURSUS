/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:40:50 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:56:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CREATE_WORD_TOKEN - Crée un token pour un mot simple.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**		- @start: index du début du mot.
**		- @len:   longueur du mot extrait.
**
**	Variables locales:
**		token  - pointeur sur t_token alloué.
**
**	Processus:
**		1. Allouer token via init_token().
**		2. Extraire la sous-chaîne par ft_substr(input, start, len).
**		3. Assigner la valeur à token->value.
**		4. Mettre token->type à T_WORD.
**		5. Appeler add_token(lexer, token).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	create_word_token(t_lexer *lexer, int start, int len)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (0);
	token->value = ft_substr(lexer->input, start, len);
	if (!token->value)
	{
		free_token(token);
		return (0);
	}
	token->type = T_WORD;
	add_token(lexer, token);
	return (1);
}

/*
** ============================================================================
**		HANDLE_WORD - Analyse et tokenise un mot simple.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**
**	Processus:
**		1. Mémoriser start = lexer->position.
**		2. Avancer tant que char valide :
**		   pas espace, opérateur, redirection ou quote.
**		3. Appeler create_word_token(lexer, start, longueur).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	handle_word(t_lexer *lexer)
{
	int		start;
	int		merging_flag;
	t_token	*last_token;

	start = lexer->position;
	while (lexer->input[lexer->position]
		&& !ft_isspace(lexer->input[lexer->position])
		&& !ft_isoperator(lexer->input[lexer->position])
		&& (lexer->input[lexer->position] != '<'
			&& lexer->input[lexer->position] != '>')
		&& !ft_isquote(lexer->input[lexer->position]))
		lexer->position++;
	merging_flag = (start > 0 && !ft_isspace(lexer->input[start - 1]));
	if (lexer->token_count > 0
		&& lexer->tokens[lexer->token_count - 1]->type == T_VAR)
		merging_flag = 0;
	if (lexer->token_count > 0
		&& lexer->tokens[lexer->token_count - 1]->type == T_REDIR)
		merging_flag = 0;
	if (!create_word_token(lexer, start, lexer->position - start))
		return (0);
	last_token = lexer->tokens[lexer->token_count - 1];
	last_token->merging = merging_flag;
	return (1);
}
