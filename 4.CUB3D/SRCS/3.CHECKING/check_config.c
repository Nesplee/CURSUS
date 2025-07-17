/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:23:17 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:05:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	check_colors(t_game *game)
{
	if (game->f_color < 0)
		exit_error("Couleur sol (F) manquante ou dupliquée");
	if (game->c_color < 0)
		exit_error("Couleur plafond (C) manquante ou dupliquée");
}

static void	check_textures(t_game *game)
{
	if (!game->text_north.path || access(game->text_north.path, R_OK))
		exit_error("Texture NO manquante ou inaccessible");
	if (!game->text_south.path || access(game->text_south.path, R_OK))
		exit_error("Texture SO manquante ou inaccessible");
	if (!game->text_west.path || access(game->text_west.path, R_OK))
		exit_error("Texture WE manquante ou inaccessible");
	if (!game->text_east.path || access(game->text_east.path, R_OK))
		exit_error("Texture EA manquante ou inaccessible");
	if (!game->text_north.img.img_ptr || !game->text_south.img.img_ptr
		|| !game->text_west.img.img_ptr || !game->text_east.img.img_ptr)
		exit_error("Échec du chargement d'une texture");
}

void	check_config(t_game *game, const char *filename)
{
	check_colors(game);
	check_textures(game);
	check_map_closed(filename, &game->map);
	check_map(&game->map, filename);
}
