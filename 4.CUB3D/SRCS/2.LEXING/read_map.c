/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:33:14 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 11:33:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	init_first(char *first_line, int *nb, int *max_w)
{
	size_t	len;

	*nb = 0;
	*max_w = 0;
	if (!first_line)
		return ;
	len = ft_strlen(first_line);
	if (len && first_line[len - 1] == '\n')
		first_line[len - 1] = '\0';
	len = ft_strlen(first_line);
	if ((int)len > *max_w)
		*max_w = len;
}

static char	**merge_first(char **lines, char *first_line, int *nb)
{
	char	**out;
	int		i;

	out = malloc(sizeof(char *) * (*nb + 2));
	if (!out)
		exit_error("Malloc failed in merge_first");
	out[0] = ft_strdup(first_line);
	i = 0;
	while (i < *nb)
	{
		out[i + 1] = lines[i];
		i++;
	}
	out[*nb + 1] = NULL;
	free(lines);
	free(first_line);
	(*nb)++;
	return (out);
}

static void	validate_nb(int nb)
{
	if (nb == 0)
		exit_error("Pas de map trouvée");
}

char	**read_map_line(int fd, int *nb_lines, int *max_width, char *first_line)
{
	char	**lines;

	init_first(first_line, nb_lines, max_width);
	lines = collect_map_body(fd, nb_lines, max_width);
	if (first_line)
		lines = merge_first(lines, first_line, nb_lines);
	validate_nb(*nb_lines);
	lines[*nb_lines] = NULL;
	return (lines);
}
