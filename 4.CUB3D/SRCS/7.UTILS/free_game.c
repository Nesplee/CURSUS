/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:06:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 16:22:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	free_frame(t_img *frame, void *mlx_ptr)
{
	if (frame->img_ptr && mlx_ptr)
	{
		mlx_destroy_image(mlx_ptr, frame->img_ptr);
		frame->img_ptr = NULL;
	}
}

void	free_rays(t_game *g)
{
	free(g->ray_array);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	free_game(t_game *g)
{
	free_textures(g);
	free_animations(g);
	free_doors(g);
	free_sprites(g);
	free_frame(&g->frame, g->mlx.mlx_ptr);
	free_rays(g);
	free_map(&g->map);
	if (g->mlx.win_ptr)
		mlx_destroy_window(g->mlx.mlx_ptr, g->mlx.win_ptr);
	if (g->mlx.mlx_ptr)
	{
		mlx_destroy_display(g->mlx.mlx_ptr);
		free(g->mlx.mlx_ptr);
	}
}
