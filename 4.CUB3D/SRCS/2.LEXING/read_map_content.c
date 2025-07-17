/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:26:28 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 11:35:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	ensure_capacity(char ***lines, int *cap, int count)
{
	char	**tmp;
	int		i;

	if (count + 1 <= *cap)
		return ;
	if (*cap > 0)
		*cap = *cap * 2;
	else
		*cap = 8;
	tmp = malloc(sizeof(char *) * (*cap));
	if (!tmp)
		exit_error("Malloc failed in read_map_lines");
	i = 0;
	while (i < count)
	{
		tmp[i] = (*lines)[i];
		i++;
	}
	free(*lines);
	*lines = tmp;
}

static char	*extract_line(char *line, int *width)
{
	int		len;
	char	*res;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	len = ft_strlen(line);
	if (len > *width)
		*width = len;
	res = ft_strdup(line);
	free(line);
	if (!res)
		exit_error("Malloc failed in extract_line");
	return (res);
}

static void	init_collect_map(char ***lines, int *count, int *cap, int *width)
{
	*lines = NULL;
	*count = 0;
	*cap = 0;
	*width = 0;
}

char	**collect_map_body(int fd, int *nb_lines, int *max_width)
{
	char	*line;
	char	**lines;
	int		count;
	int		cap;

	init_collect_map(&lines, &count, &cap, max_width);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line && *line != '\n')
		{
			ensure_capacity(&lines, &cap, count);
			lines[count++] = extract_line(line, max_width);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	*nb_lines = count;
	lines[count] = NULL;
	return (lines);
}
