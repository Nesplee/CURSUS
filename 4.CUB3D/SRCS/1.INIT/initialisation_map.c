/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:24:22 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:28:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	init_frame(t_img *frame, void *mlx_ptr)
{
	frame->img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!frame->img_ptr)
		exit_error("init_frame: impossible de créer l'image");
	frame->data = mlx_get_data_addr(frame->img_ptr, &frame->bpp,
			&frame->line_length, &frame->endian);
	frame->width = WIN_WIDTH;
	frame->height = WIN_HEIGHT;
}

void	init_texture(t_texture *tex, char *path, t_mlx *mlx)
{
	tex->path = ft_strdup(path);
	if (!tex->path)
		exit_error("init_texture: échec de duplication du chemin");
	tex->img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&tex->img.width, &tex->img.height);
	if (!tex->img.img_ptr)
		exit_error("init_texture: impossible de charger la texture");
	tex->img.data = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.line_length, &tex->img.endian);
}

static char	*pad_line(const char *line, int max_w)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(line);
	res = malloc(max_w + 1);
	if (!res)
		exit_error("pad_line: malloc failed");
	i = 0;
	while (i < max_w)
	{
		if (i < len)
			res[i] = line[i];
		else
			res[i] = '1';
		i++;
	}
	res[max_w] = '\0';
	return (res);
}

void	init_map(t_map *map, char **lines, int nb_lines, int max_width)
{
	int	i;

	map->height = nb_lines;
	map->width = max_width;
	map->grid = ft_calloc(nb_lines, sizeof(char *));
	if (!map->grid)
		exit_error("init_map: Echec du malloc map->grid");
	i = 0;
	while (i < nb_lines)
	{
		map->grid[i] = pad_line(lines[i], max_width);
		i++;
	}
}
