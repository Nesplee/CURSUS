/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:03:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 11:27:28 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	is_texture_id(char *id)
{
	if (id == NULL)
		return (0);
	if (ft_strcmp(id, "NO") == 0)
		return (1);
	if (ft_strcmp(id, "SO") == 0)
		return (1);
	if (ft_strcmp(id, "WE") == 0)
		return (1);
	if (ft_strcmp(id, "EA") == 0)
		return (1);
	return (0);
}

void	parse_texture(char *id, char *raw_path, t_game *g)
{
	char	*path;

	if (!raw_path)
		exit_error("parse_texture: path manquant");
	path = ft_strtrim(raw_path, " \t\n");
	if (!path)
		exit_error("parse_texture: échec trim");
	if (open(path, O_RDONLY) < 0)
		exit_error("Texture NO manquante ou inaccessible");
	if (!ft_strcmp(id, "NO"))
		init_texture(&g->text_north, path, &g->mlx);
	else if (!ft_strcmp(id, "SO"))
		init_texture(&g->text_south, path, &g->mlx);
	else if (!ft_strcmp(id, "WE"))
		init_texture(&g->text_west, path, &g->mlx);
	else if (!ft_strcmp(id, "EA"))
		init_texture(&g->text_east, path, &g->mlx);
	else
		exit_error("Directive texture inconnue");
	free(path);
}
