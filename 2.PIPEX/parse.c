/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:23:57 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/07 11:35:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_quoted_len(const char *s, char quote)
{
	int	len;

	len = 1;
	while (s[len] && s[len] != quote)
		len++;
	if (s[len] == quote)
		return (len + 1);
	return (0);
}

static int	get_arg_len(const char *s, char *q)
{
	int	len;

	if (*s == '\'')
	{
		*q = '\'';
		return (get_quoted_len(s, '\''));
	}
	if (*s == '"')
	{
		*q = '"';
		return (get_quoted_len(s, '"'));
	}
	*q = 0;
	len = 0;
	while (s[len] && !ft_isspace(s[len]) && s[len] != '\'' && s[len] != '"')
		len++;
	return (len);
}

static char	*extract_arg(const char *str, int *i)
{
	char	*res;
	char	q;
	int		len;
	int		start;

	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	start = *i;
	len = get_arg_len(str + *i, &q);
	if (len <= 0)
		return (NULL);
	if (q)
		res = ft_substr(str, start + 1, len - 2);
	else
		res = ft_substr(str, start, len);
	*i = *i + len;
	return (res);
}

char	**parse_cmds(const char *cmd)
{
	char	**args;
	char	*tmp;
	int		i;
	int		j;

	if (!cmd || !*cmd)
		return (NULL);
	args = ft_calloc((ft_strlen(cmd) + 1), sizeof(char *));
	if (!args)
		error_exit(ERR_MEM);
	i = 0;
	j = 0;
	tmp = extract_arg(cmd, &i);
	while (tmp)
	{
		args[j++] = tmp;
		tmp = extract_arg(cmd, &i);
	}
	if (j == 0)
	{
		free(args);
		return (NULL);
	}
	args[j] = NULL;
	return (args);
}
