/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:53:49 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:52:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CREATE_VAR_TOKEN - Crée un token pour variable.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**		- @start: index du '$'.
**		- @len: longueur du nom (incluant '$').
**
**	Variables locales:
**		token: pointeur sur t_token alloué.
**
**	Processus:
**		1. Allouer token via init_token().
**		2. Configurer type=T_VAR.
**		3. Extraire value via ft_substr().
**		4. Appeler add_token().
**
**	Retour:
**		1 si succès, 0 sinon.
*/

static int	create_var_token(t_lexer *lexer, int start, int len)
{
	t_token	*token;

	token = init_token();
	if (!token)
		return (0);
	token->type = T_VAR;
	token->value = ft_substr(lexer->input, start, len);
	if (!token->value)
	{
		free_token(token);
		return (0);
	}
	add_token(lexer, token);
	return (1);
}

/*
** ============================================================================
**		HANDLE_VARIABLE - Tokenise une variable.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**
**	Processus:
**		1. Sauvegarder start = lexer->position.
**		2. lexer->position++ pour passer le '$'.
**		3. Si lexer->input[start + 1] == '?' :
**			- lexer->position++ ; longueur = 2.
**		  Sinon :
**			- Tant que caractère alnum ou '_' :
**				lexer->position++.
**			- longueur = lexer->position - start.
**		4. Appeler create_var_token(lexer, start, longueur).
**
**	Retour:
**		1 si succès, 0 sinon.
*/

static void	set_merging_flag(t_lexer *lexer, int start)
{
	if (start > 0 && !ft_isspace(lexer->input[start - 1]))
		lexer->tokens[lexer->token_count - 1]->merging = 1;
	else
		lexer->tokens[lexer->token_count - 1]->merging = 0;
}

static int	process_variable(t_lexer *lexer, int start)
{
	int	len;

	if (lexer->input[lexer->position] == '?')
	{
		lexer->position++;
		len = 2;
		if (!create_var_token(lexer, start, len))
			return (0);
	}
	else
	{
		while (lexer->input[lexer->position]
			&& (ft_isalnum(lexer->input[lexer->position])
				|| lexer->input[lexer->position] == '_'))
		{
			lexer->position++;
		}
		len = lexer->position - start;
		if (!create_var_token(lexer, start, len))
			return (0);
	}
	return (1);
}

int	handle_variable(t_lexer *lexer)
{
	int		start;
	char	next;

	start = lexer->position;
	lexer->position++;
	next = lexer->input[lexer->position];
	if (ft_isdigit((unsigned char)next))
	{
		lexer->position++;
		if (!create_var_token(lexer, start, 2))
			return (0);
		set_merging_flag(lexer, start);
		return (1);
	}
	if (next == '\0'
		|| (!ft_isalnum(next) && next != '_' && next != '?'))
	{
		lexer->position = start;
		return (handle_word(lexer));
	}
	if (!process_variable(lexer, start))
		return (0);
	set_merging_flag(lexer, start);
	return (1);
}
