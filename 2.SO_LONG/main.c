/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:42:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 20:46:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		handle_movement(keycode, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(&game, ERR_ARGS);
	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv[1]);
	if (!game.map)
		error_exit(&game, ERR_MAP);
	game.map_height = 0;
	while (game.map[game.map_height] != NULL)
		game.map_height++;
	game.map_width = ft_strlen(game.map[0]);
	check_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit(&game, ERR_MLX);
	init_window(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
