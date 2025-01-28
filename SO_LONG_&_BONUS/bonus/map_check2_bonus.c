/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:29:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:21:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_rectangular(char **map)
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

int	check_walls(char **map)
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

static void	count_components(t_game *game, int *p, int *e, int i)
{
	int	j;

	j = -1;
	while (game->map[i][++j])
	{
		if (game->map[i][j] == 'P')
		{
			(*p)++;
			game->player_x = j;
			game->player_y = i;
		}
		else if (game->map[i][j] == 'E')
			(*e)++;
		else if (game->map[i][j] == 'C')
			game->collectibles++;
		else if (game->map[i][j] == 'N')
			game->enemy_count++;
	}
}

int	check_components(t_game *game)
{
	int	i;
	int	p;
	int	e;

	p = 0;
	e = 0;
	game->collectibles = 0;
	game->enemy_count = 0;
	i = -1;
	while (game->map[++i])
		count_components(game, &p, &e, i);
	return (p == 1 && e == 1 && game->collectibles > 0);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
