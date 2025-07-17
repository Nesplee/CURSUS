/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:27:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 11:27:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	set_color(char id, int rgb[3], t_game *g)
{
	int	col;

	col = (rgb[0] << 16) | rgb[1] << 8 | rgb[2];
	if (id == 'F')
	{
		if (g->f_color != -1)
			exit_error("Directive F dupliquée");
		g->f_color = col;
	}
	else if (id == 'C')
	{
		if (g->c_color != -1)
			exit_error("Directive C dupliquée");
		g->c_color = col;
	}
	else
		exit_error("Directive couleur inconnue");
}

static int	validate_color_component(char *raw, char **parts)
{
	char	*trim;
	int		val;

	trim = ft_strtrim(raw, " \t\n");
	if (!trim)
		color_error(parts, NULL);
	if (!ft_isnumber(trim))
		color_error(parts, trim);
	val = ft_atoi(trim);
	free(trim);
	if (val < 0 || val > 255)
		color_error(parts, NULL);
	return (val);
}

void	parse_color(char id, char *vals, t_game *g)
{
	char	**parts;
	int		rgb[3];
	int		i;

	parts = ft_split(vals, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		color_error(parts, NULL);
	i = 0;
	while (i < 3)
	{
		rgb[i] = validate_color_component(parts[i], parts);
		i++;
	}
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	set_color(id, rgb, g);
}
