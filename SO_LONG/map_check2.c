/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:29:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/22 20:32:04 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
