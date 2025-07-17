/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:00:20 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 11:55:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	parse_cub(const char *file, t_game *g)
{
	int		fd;
	int		nb;
	int		w;
	char	**lines;
	char	*first_line;

	g->f_color = -1;
	g->c_color = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("Impossible d'ouvrir .cub");
	read_next_directive(fd, g, &first_line);
	lines = read_map_line(fd, &nb, &w, first_line);
	close(fd);
	init_map(&g->map, lines, nb, w);
	free_tab(lines);
	check_config(g, file);
}
