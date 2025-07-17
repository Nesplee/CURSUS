/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:36:50 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 14:17:53 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/cub3d.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit_error("Usage: ./cub3d <map.cub>");
	on_exit(cleanup, &game);
	signal(SIGINT,  SIG_DFL);
	ft_memset(&game, 0, sizeof(game));
	init_mlx(&game.mlx);
	parse_cub(argv[1], &game);
	check_map(&game.map, argv[1]);
	init_game(&game);
	if (game.nb_doors > 0)
		init_doors_images(&game);
	init_hooks(&game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
