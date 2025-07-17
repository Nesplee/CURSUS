/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_raycasting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:29:01 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 11:46:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	init_ray_array(t_game *game)
{
	game->ray_array = malloc(WIN_WIDTH * sizeof(t_ray));
	if (!game->ray_array)
		exit_error("init_ray_array: echec d’allocation du ray_array");
}

void	init_raycast_config(t_raycast_config *cfg)
{
	cfg->fov = M_PI / 3;
	cfg->plane_y = 0.66;
}
