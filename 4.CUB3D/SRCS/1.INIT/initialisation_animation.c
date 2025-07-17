/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_animation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:15:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:22:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static char	*build_anim_path(char *base, int idx)
{
	char	*nbr;
	char	*tmp;
	char	*path;

	nbr = ft_itoa(idx);
	tmp = ft_strjoin(base, nbr);
	free(nbr);
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	return (path);
}

static void	init_direction_anim(t_anim *anim, char *base_path, t_mlx *mlx)
{
	char	*path;
	int		i;

	anim->current = 0;
	anim->timer = 0.0;
	i = 0;
	while (i < ANIM_FRAMES)
	{
		path = build_anim_path(base_path, i);
		init_texture(&anim->frames[i], path, mlx);
		free(path);
		i++;
	}
}

void	init_animations(t_game *g)
{
	init_direction_anim(&g->anim_north, "./TEXTURES/TEXTURE_NO/texture_NO_",
		&g->mlx);
	init_direction_anim(&g->anim_south, "./TEXTURES/TEXTURE_SO/texture_SO_",
		&g->mlx);
	init_direction_anim(&g->anim_east, "./TEXTURES/TEXTURE_EA/texture_EA_",
		&g->mlx);
	init_direction_anim(&g->anim_west, "./TEXTURES/TEXTURE_WE/texture_WE_",
		&g->mlx);
}
