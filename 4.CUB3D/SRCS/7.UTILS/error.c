/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:09:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/10/14 16:23:55 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	exit_error(const char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd((char *)msg, 2);
	exit(EXIT_FAILURE);
}

void	color_error(char **parts, char *trim)
{
	if (trim)
		free(trim);
	free_tab(parts);
	exit_error("Format RGB attendu: xxx,xxx,xxx. Valeurs entre 0 et 255");
}

int	close_window(t_game *g)
{
	free_game(g);
	exit(0);
	return (0);
}

void	cleanup(int status, void *arg)
{
	(void)status;
	(void)arg;
}
