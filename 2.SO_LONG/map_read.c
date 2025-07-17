/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 20:33:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/img_player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/img_wall.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible1.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/img_floor.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/img_exit.xpm", &width, &height);
	if (!game->img_player || !game->img_wall || !game->img_collect
		|| !game->img_floor || !game->img_exit)
	{
		ft_printf("Error: Failed to load images\n");
		close_window(game);
	}
}
