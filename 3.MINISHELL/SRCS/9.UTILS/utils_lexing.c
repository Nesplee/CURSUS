/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:18 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:14:04 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	FT_SKIP_SPACES - Avance le lexer après les espaces
** ============================================================================
**	Paramètres:
**		- @lexer: Structure du lexer contenant input et position
**
**	Processus:
**		1. Tant qu'on est dans input et ft_isspace(), incrémenter position.
**
**	Retour:
**		(void)
*/
void	ft_skip_spaces(t_lexer *lexer)
{
	while (lexer->input[lexer->position]
		&& ft_isspace(lexer->input[lexer->position]))
		lexer->position++;
}

/*
** ============================================================================
**	ADD_TOKEN - Ajoute un token au tableau de tokens
** ============================================================================
**	Paramètres:
**		- @lexer: Structure du lexer contenant les tokens et leur count
**		- @token: Token à ajouter
**
**	Processus:
**		1. Placer token dans lexer->tokens à l’indice lexer->token_count.
**		2. Incrémenter lexer->token_count.
**
**	Retour:
**		(void)
*/
void	add_token(t_lexer *lexer, t_token *token)
{
	lexer->tokens[lexer->token_count++] = token;
}

/*
** ============================================================================
**	GET_FORMATTED_TOKEN - Formate le token (1 ou 2 caractères)
** ============================================================================
**	Paramètres:
**		- @token: Chaîne issue du lexer
**		- @buf:   Buffer (taille >= 3) pour copier le token formaté
**
**	Processus:
**		1. Déterminer len = 2 si opérateur double, sinon len = 1.
**		2. Copier token[0] et, si len == 2, token[1] dans buf.
**		3. Terminer buf par '\0'.
**
**	Retour:
**		(void)
*/
static void	get_formatted_token(char *token, char *buf)
{
	int	len;

	if ((token[0] == '<' && token[1] == '<')
		|| (token[0] == '>' && token[1] == '>')
		|| (token[0] == '&' && token[1] == '&')
		|| (token[0] == '|' && token[1] == '|'))
		len = 2;
	else
		len = 1;
	buf[0] = token[0];
	if (len == 2)
		buf[1] = token[1];
	buf[len] = '\0';
}

/*
** ============================================================================
**	PRINT_LEXER_ERROR - Affiche l'erreur spécifique du lexer
** ============================================================================
**	Paramètres:
**		- @error: Code d'erreur (ERR_SYNTAX, ERR_VAR_SYNTAX, etc.)
**		- @token: Token ayant généré l'erreur
**
**	Processus:
**		1. Formater le token via get_formatted_token().
**		2. Selon error, appeler la fonction dis_* adéquate.
**
**	Retour:
**		(void)
*/
void	print_lexer_error(int error, char *token)
{
	char	buf[3];

	get_formatted_token(token, buf);
	if (error == ERR_SYNTAX)
		dis_syntax_err_custom(buf);
	else if (error == ERR_VAR_SYNTAX)
		dis_var_syntax_err(buf);
	else if (error == ERR_PAREN_EMPTY)
		dis_paren_empty_err();
	else if (error == ERR_PAREN_MISMATCH)
		dis_paren_mismatch_err();
	else if (error == ERR_PIPE)
		dis_pipe_err();
	else
		dis_syntax_err_custom(buf);
}
