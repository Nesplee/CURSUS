/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:38:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/22 20:36:24 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
	}
	return (1);
}

static int	check_walls(char **map)
{
	int	i;
	int	j;
	int	height;

	height = 0;
	while (map[height])
		height++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || i == height - 1 || j == 0
					|| j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!check_valid_chars(game->map))
		error_exit(game, ERR_CHAR);
	if (!check_rectangular(game->map))
		error_exit(game, ERR_RECT);
	if (!check_walls(game->map))
		error_exit(game, ERR_WALLS);
	if (!check_components(game))
		error_exit(game, ERR_COMPONENTS);
	if (!check_valid_path(game))
		error_exit(game, ERR_PATH);
	return (1);
}
