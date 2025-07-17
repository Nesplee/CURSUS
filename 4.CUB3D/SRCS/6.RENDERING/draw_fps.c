/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:30:27 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 13:50:17 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	record_sample(double delta, double history[], int *idx, int *cnt)
{
	double	sample;

	if (delta <= 0.0001)
		delta = 0.0001;
	sample = 1.0 / delta;
	history[*idx] = sample;
	*idx = *idx + 1;
	if (*idx >= FPS_SAMPLES)
		*idx = 0;
	if (*cnt < FPS_SAMPLES)
		*cnt = *cnt + 1;
}

static double	compute_avg(double history[], int cnt)
{
	double	sum;
	int		i;

	sum = 0.0;
	i = 0;
	while (i < cnt)
	{
		sum += history[i];
		i++;
	}
	if (cnt > 0)
		return (sum / cnt);
	return (0.0);
}

static char	*build_fps_string(int val)
{
	char	*nbr;
	char	*str;

	nbr = ft_itoa(val);
	str = ft_strjoin("FPS: ", nbr);
	free(nbr);
	return (str);
}

static char	*format_fps(double delta)
{
	static double	history[FPS_SAMPLES];
	static int		idx;
	static int		cnt;
	double			avg;

	record_sample(delta, history, &idx, &cnt);
	avg = compute_avg(history, cnt);
	return (build_fps_string((int)(avg + 0.5)));
}

void	draw_fps_ui(t_game *g, double delta)
{
	char	*fps;
	int		y;

	fps = format_fps(delta);
	y = g->map.height * MINIMAP_SCALE + 5;
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win_ptr, 5, y, CROSSHAIR_COLOR, fps);
	free(fps);
}
