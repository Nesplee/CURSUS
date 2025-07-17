/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:12:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 14:12:14 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

double	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		exit_error("get_time: échec de gettimeofday");
	return (tv.tv_sec + tv.tv_usec / 1e6);
}

int	game_loop(void *param)
{
	t_game	*g;
	double	now;
	double	delta;

	g = (t_game *)param;
	now = get_time();
	delta = now - g->old_time;
	g->old_time = now;
	update_animations(g, delta);
	update_player(g, delta);
	render_all(g, delta);
	return (0);
}
