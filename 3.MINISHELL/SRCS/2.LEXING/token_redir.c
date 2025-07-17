/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:12:50 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 13:07:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			CREATE_REDIR_TOKEN - Crée un token pour redirections.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**		- @type:	t_redirection_type (INPUT, OUTPUT, APPEND, HEREDOC).
**		- @value:	chaîne C ("<", ">", ">>", "<<").
**		- @advance:	nombre de caractères à avancer.
**
**	Variables locales:
**		token - pointeur sur t_token alloué.
**
**	Processus:
**		1. Allouer token via init_token().
**		2. token->type=T_REDIR, token->redir=type.
**		3. Dupliquer value dans token->value.
**		4. En cas d’erreur, libérer token et retourner 0.
**		5. Avancer lexer->position de advance.
**		6. add_token(lexer, token).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	create_redir_token(t_lexer *lexer, t_redirection_type type,
	char *value, int advance)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (0);
	token->type = T_REDIR;
	token->redir = type;
	token->value = ft_strdup(value);
	if (!token->value)
	{
		free_token(token);
		return (0);
	}
	token->merging = 0;
	lexer->position += advance;
	add_token(lexer, token);
	return (1);
}

/*
** ============================================================================
**			HANDLE_REDIRECTION - Tokenise une redirection.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**
**	Processus:
**		1. Vérifier caractère (< ou >).
**		2. Tester redirection double (<< ou >>).
**		3. Appeler create_redir_token() avec les bons args.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	handle_redirection(t_lexer *lexer)
{
	if (lexer->input[lexer->position] == '<')
	{
		if (lexer->input[lexer->position + 1] == '<')
			return (create_redir_token(lexer, REDIR_HEREDOC, "<<", 2));
		return (create_redir_token(lexer, REDIR_INPUT, "<", 1));
	}
	if (lexer->input[lexer->position + 1] == '>')
		return (create_redir_token(lexer, REDIR_APPEND, ">>", 2));
	return (create_redir_token(lexer, REDIR_OUTPUT, ">", 1));
}
