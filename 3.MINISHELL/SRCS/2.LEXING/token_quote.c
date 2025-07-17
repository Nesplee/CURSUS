/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:22:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/04 17:34:55 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

static char	*extract_quote_value(t_lexer *lexer, int *opening_quote_index,
		char *quote)
{
	int		start;
	char	*value;

	*opening_quote_index = lexer->position;
	*quote = lexer->input[lexer->position];
	lexer->position++;
	start = lexer->position;
	while (lexer->input[lexer->position]
		&& lexer->input[lexer->position] != *quote)
		lexer->position++;
	if (!lexer->input[lexer->position])
		return (NULL);
	value = ft_substr(lexer->input, start, lexer->position - start);
	lexer->position++;
	return (value);
}

static t_token	*create_quote_token(t_lexer *lexer, char *value,
		int opening_quote_index, char quote_char)
{
	t_token	*token;

	token = init_token();
	if (!token)
	{
		free(value);
		return (NULL);
	}
	token->type = T_WORD;
	token->value = value;
	if (quote_char == '"')
		token->quote = DOUBLE_QUOTE;
	else
		token->quote = NO_QUOTE;
	if (opening_quote_index > 0
		&& !ft_isspace(lexer->input[opening_quote_index - 1]))
		token->merging = 1;
	else
		token->merging = 0;
	return (token);
}

int	handle_quote(t_lexer *lexer)
{
	int		opening_quote_index;
	char	quote;
	char	*value;
	t_token	*token;

	value = extract_quote_value(lexer, &opening_quote_index, &quote);
	if (!value)
		return (0);
	token = create_quote_token(lexer, value, opening_quote_index, quote);
	if (!token)
		return (0);
	add_token(lexer, token);
	return (1);
}
