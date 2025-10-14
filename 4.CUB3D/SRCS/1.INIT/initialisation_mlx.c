/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:13:59 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 16:11:26 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit_error("init_mlx: échec de mlx_init");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Cub3D");
	if (!mlx->win_ptr)
		exit_error("init_mlx: échec de mlx_new_window");
}

void	init_game(t_game *g)
{
	init_animations(g);
	init_input(&g->input);
	init_player(g);
	set_player_spawn(g);
	init_doors(g);
	init_raycast_config(&g->raycast_cfg);
	init_ray_array(g);
	init_frame(&g->frame, g->mlx.mlx_ptr);
	g->mouse_locked = 0;
	g->old_time = get_time();
}
