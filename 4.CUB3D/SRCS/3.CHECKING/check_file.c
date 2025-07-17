/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:53:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:17:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static int	check_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

static int	check_map_chars(t_map *map)
{
	int		i;
	int		j;
	int		start_count;
	char	c;

	i = 0;
	start_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->grid[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				start_count++;
			else if (c != '0' && c != '1' && c != ' ' && c != 'D')
				return (0);
			j++;
		}
		i++;
	}
	return (start_count == 1);
}

void	check_map(t_map *map, const char *filename)
{
	if (!check_extension(filename))
		exit_error("Extension .cub invalide");
	if (!check_map_chars(map))
		exit_error("Caractères invalides ou spawn incorrect");
}
