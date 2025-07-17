/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:54:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 02:13:02 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minishell.h"

static int	count_tokens(t_token **tokens)
{
	int	total;

	total = 0;
	while (tokens[total])
		total++;
	return (total);
}

static int	merge_token_values(t_token **tokens, int *i, int total)
{
	int		start;
	t_token	*base;
	char	*temp;

	start = *i;
	base = tokens[start];
	temp = ft_strdup(base->value);
	if (!temp)
		return (0);
	while (*i + 1 < total && tokens[*i + 1]->merging == 1
		&& (tokens[*i + 1]->type == T_WORD || tokens[*i + 1]->type == T_VAR))
	{
		if (tokens[*i + 1]->quote == DOUBLE_QUOTE)
			base->quote = DOUBLE_QUOTE;
		temp = ft_strjoin_free(temp, tokens[*i + 1]->value);
		free_token(tokens[*i + 1]);
		(*i)++;
	}
	free(base->value);
	base->value = temp;
	return (1);
}

t_token	**merge_adjacent_tokens(t_token **tokens)
{
	int		total;
	int		i;
	int		j;
	int		group_start;
	t_token	**merged;

	total = count_tokens(tokens);
	merged = malloc(sizeof(t_token *) * (total + 1));
	if (!merged)
		return (NULL);
	i = 0;
	j = 0;
	while (i < total)
	{
		group_start = i;
		if (!merge_token_values(tokens, &i, total))
			return (NULL);
		merged[j++] = tokens[group_start];
		i++;
	}
	merged[j] = NULL;
	free(tokens);
	return (merged);
}
