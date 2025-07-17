/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:41:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 14:02:21 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	free_single_texture(void *mlx_ptr, t_texture *tex)
{
	if (tex->path)
	{
		free(tex->path);
		tex->path = NULL;
	}
	if (tex->img.img_ptr)
		mlx_destroy_image(mlx_ptr, tex->img.img_ptr);
}

void	free_textures(t_game *g)
{
	free_single_texture(g->mlx.mlx_ptr, &g->text_north);
	free_single_texture(g->mlx.mlx_ptr, &g->text_south);
	free_single_texture(g->mlx.mlx_ptr, &g->text_west);
	free_single_texture(g->mlx.mlx_ptr, &g->text_east);
}

void	free_doors(t_game *g)
{
	int	i;

	if (!g->doors)
		return ;
	i = 0;
	while (i < g->nb_doors)
	{
		if (g->doors[i].anim[0].path)
			free(g->doors[i].anim[0].path);
		if (g->doors[i].anim[0].img.img_ptr)
			mlx_destroy_image(g->mlx.mlx_ptr,
				g->doors[i].anim[0].img.img_ptr);
		if (g->doors[i].anim[1].path)
			free(g->doors[i].anim[1].path);
		if (g->doors[i].anim[1].img.img_ptr)
			mlx_destroy_image(g->mlx.mlx_ptr,
				g->doors[i].anim[1].img.img_ptr);
		i++;
	}
	free(g->doors);
}

void	free_sprites(t_game *g)
{
	int	i;
	int	j;

	if (!g->sprites)
		return ;
	i = 0;
	while (i < g->nb_sprites)
	{
		if (g->sprites[i].frames)
		{
			j = 0;
			while (j < g->sprites[i].num_frames)
			{
				if (g->sprites[i].frames[j].img_ptr)
					mlx_destroy_image(g->mlx.mlx_ptr,
						g->sprites[i].frames[j].img_ptr);
				j++;
			}
			free(g->sprites[i].frames);
		}
		i++;
	}
	free(g->sprites);
}
