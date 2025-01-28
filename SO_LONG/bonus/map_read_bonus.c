/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/24 18:06:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_map_file(char *filename)
{
	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
		return (0);
	return (1);
}

static char	*read_lines(int fd)
{
	char	*line;
	char	*tmp;
	char	*map_str;

	map_str = ft_strdup("");
	if (!map_str)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_str, line);
		if (!tmp)
		{
			free(map_str);
			free(line);
			return (NULL);
		}
		free(map_str);
		free(line);
		map_str = tmp;
		line = get_next_line(fd);
	}
	return (map_str);
}

char	**read_map(t_game *game, char *filename)
{
	int		fd;
	char	*map_str;
	char	**map;

	if (!check_map_file(filename))
		error_exit(game, ERR_FILE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, ERR_FILE_OPEN);
	map_str = read_lines(fd);
	if (!map_str)
	{
		close(fd);
		error_exit(game, ERR_MAP);
	}
	close(fd);
	map = ft_split(map_str, '\n');
	if (!map)
	{
		free(map_str);
		error_exit(game, ERR_MAP);
	}
	free(map_str);
	game->map = map;
	return (map);
}

void	render_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_floor(game);
	render_walls(game);
	render_exit(game);
	render_collectibles(game);
	render_enemies(game);
	render_player(game);
	render_hud(game);
	mlx_do_sync(game->mlx);
}
