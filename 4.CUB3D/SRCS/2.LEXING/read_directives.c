/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:45:35 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/12 16:50:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static char	*get_trimmed_line(int fd)
{
	char	*raw;
	char	*trim;

	raw = get_next_line(fd);
	while (raw != NULL)
	{
		trim = ft_strtrim(raw, " \t\n");
		free(raw);
		if (*trim != '\0')
			return (trim);
		free(trim);
		raw = get_next_line(fd);
	}
	return (NULL);
}

static int	process_tokens(char **tok, t_game *g)
{
	if (is_texture_id(tok[0]) && tok[1])
		parse_texture(tok[0], tok[1], g);
	else if ((tok[0][0] == 'F' || tok[0][0] == 'C') && tok[1])
		parse_color(tok[0][0], tok[1], g);
	else
		return (0);
	return (1);
}

int	read_next_directive(int fd, t_game *g, char **first_map_line)
{
	char	*line;
	char	**tok;

	*first_map_line = NULL;
	line = get_trimmed_line(fd);
	while (line != NULL)
	{
		tok = ft_split(line, ' ');
		if (!tok || !tok[0])
		{
			free(line);
			exit_error("Directive vide");
		}
		if (process_tokens(tok, g) == 0)
		{
			*first_map_line = line;
			free_tab(tok);
			return (0);
		}
		free_tab(tok);
		free(line);
		line = get_trimmed_line(fd);
	}
	exit_error("Fichier .cub incomplet (directives manquantes)");
	return (0);
}
