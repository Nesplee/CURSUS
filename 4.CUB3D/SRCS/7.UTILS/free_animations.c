/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:00:33 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 16:18:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	free_anim_frames(void *mlx_ptr, t_anim *anim)
{
	int	i;

	i = 0;
	while (i < ANIM_FRAMES)
	{
		if (anim->frames[i].img.img_ptr && mlx_ptr)
			mlx_destroy_image(mlx_ptr,
				anim->frames[i].img.img_ptr);
		if (anim->frames[i].path)
		{
			free(anim->frames[i].path);
			anim->frames[i].path = NULL;
		}
		anim->frames[i].img.img_ptr = NULL;
		i++;
	}
}

void	free_animations(t_game *g)
{
	free_anim_frames(g->mlx.mlx_ptr, &g->anim_north);
	free_anim_frames(g->mlx.mlx_ptr, &g->anim_south);
	free_anim_frames(g->mlx.mlx_ptr, &g->anim_east);
	free_anim_frames(g->mlx.mlx_ptr, &g->anim_west);
}
