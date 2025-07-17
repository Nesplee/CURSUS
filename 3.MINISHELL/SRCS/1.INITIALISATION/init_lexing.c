/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:39:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 14:39:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			INIT_TOKEN - Alloue et initialise un token par défaut.
** ============================================================================
**	Parametres:
**		(aucun)
**
**	Variables locales :
**		token  - pointeur sur t_token alloué.
**
**	Processus :
**		1. Allouer la structure t_token.
**		2. Initialiser les champs :
**		   - type à T_WORD
**		   - quote à NO_QUOTE
**		   - redir à REDIR_INPUT
**		   - ope à OP_PIPE
**		   - value à NULL
**
**	Retour :
**		Pointeur sur token si succès, NULL sinon.
*/
t_token	*init_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = T_WORD;
	token->quote = NO_QUOTE;
	token->redir = REDIR_INPUT;
	token->ope = OP_PIPE;
	token->value = NULL;
	token->merging = 0;
	return (token);
}

/*
** ============================================================================
**			INIT_LEXER - Alloue et initialise le lexer pour une entrée.
** ============================================================================
**	Parametres:
**		- @input: chaîne C à analyser.
**
**	Variables locales :
**		lexer  - pointeur sur t_lexer alloué.
**
**	Processus :
**		1. Allouer la structure t_lexer.
**		2. Dupliquer input dans lexer->input via ft_strdup().
**		3. Initialiser les champs :
**		   - position à 0
**		   - tokens à NULL
**		   - token_count à 0
**		4. Si ft_strdup échoue, libérer lexer et retourner NULL.
**
**	Retour :
**		Pointeur sur lexer si succès, NULL sinon.
*/
t_lexer	*init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input = ft_strdup(input);
	if (!lexer->input)
	{
		free(lexer);
		return (NULL);
	}
	lexer->position = 0;
	lexer->tokens = NULL;
	lexer->token_count = 0;
	return (lexer);
}
