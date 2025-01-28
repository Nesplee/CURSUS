/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:53:55 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/24 16:44:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**duplicate_map(char **map, int height)
{
	char	**dup;
	int		i;

	dup = ft_calloc(height + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free_map(dup);
			return (NULL);
		}
	}
	return (dup);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static int	check_collected(char **temp_map, t_game *game)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			if (game->map[i][j] == 'C' && temp_map[i][j] == 'V')
				collectibles++;
	}
	return (collectibles == game->collectibles);
}

static int	check_exit_accessible(char **map, char **temp_map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (map[i][j] == 'E' &&
				((i > 0 && temp_map[i - 1][j] == 'V')
				|| (i < game->map_height - 1 && temp_map[i + 1][j] == 'V')
				|| (j > 0 && temp_map[i][j - 1] == 'V')
				|| (j < game->map_width - 1 && temp_map[i][j + 1] == 'V')))
				return (1);
		}
	}
	return (0);
}

int	check_valid_path(t_game *game)
{
	char	**temp_map;
	int		valid_path;

	temp_map = duplicate_map(game->map, game->map_height);
	if (!temp_map)
		return (0);
	flood_fill(temp_map, game->player_x, game->player_y, game);
	valid_path = check_collected(temp_map, game);
	if (valid_path)
		valid_path = check_exit_accessible(game->map, temp_map, game);
	free_map(temp_map);
	return (valid_path);
}
