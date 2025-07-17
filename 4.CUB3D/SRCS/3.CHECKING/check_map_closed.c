/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:48:23 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:07:17 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static int	is_valid_pos(t_map *map, int i, int j)
{
	if (i < 0 || i >= map->height || j < 0 || j >= map->width)
		return (0);
	return (1);
}

static int	check_line_neighbors(t_map *map, int i, int j, int di)
{
	int	dj;
	int	ni;

	ni = i + di;
	dj = -1;
	while (dj <= 1)
	{
		if (di == 0 && dj == 0)
		{
			dj++;
			continue ;
		}
		if (!is_valid_pos(map, ni, j + dj)
			|| map->grid[ni][j + dj] == ' '
			|| map->grid[ni][j + dj] == '\0')
			return (0);
		dj++;
	}
	return (1);
}

static int	check_surrounding(t_map *map, int i, int j)
{
	int	di;

	di = -1;
	while (di <= 1)
	{
		if (!check_line_neighbors(map, i, j, di))
			return (0);
		di++;
	}
	return (1);
}

static int	is_map_closed(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->grid[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (!check_surrounding(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map_closed(const char *filename, t_map *map)
{
	(void)filename;
	if (!is_map_closed(map))
		exit_error("Map non fermée");
}
