/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:30:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:33:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	handle_movement_keys(int key, t_game *g)
{
	if (key == KEY_W)
		g->input.key_w = 1;
	if (key == KEY_S)
		g->input.key_s = 1;
	if (key == KEY_A)
		g->input.key_a = 1;
	if (key == KEY_D)
		g->input.key_d = 1;
	if (key == KEY_UP)
		g->input.key_up = 1;
	if (key == KEY_DOWN)
		g->input.key_down = 1;
	if (key == KEY_LEFT)
		g->input.key_left = 1;
	if (key == KEY_RIGHT)
		g->input.key_right = 1;
}

static void	handle_action_keys(int key, t_game *g)
{
	if (key == KEY_SPACE)
		g->input.key_space = 1;
	if (key == KEY_E)
	{
		g->input.key_e = 1;
		try_toggle_door(g);
	}
	if (key == KEY_SHIFT)
		g->input.key_shift = 1;
	if (key == KEY_ESC)
		exit(0);
}

int	key_press(int key, t_game *g)
{
	handle_movement_keys(key, g);
	handle_action_keys(key, g);
	return (0);
}

int	key_release(int key, t_game *g)
{
	if (key == KEY_W)
		g->input.key_w = 0;
	if (key == KEY_S)
		g->input.key_s = 0;
	if (key == KEY_A)
		g->input.key_a = 0;
	if (key == KEY_D)
		g->input.key_d = 0;
	if (key == KEY_UP)
		g->input.key_up = 0;
	if (key == KEY_DOWN)
		g->input.key_down = 0;
	if (key == KEY_LEFT)
		g->input.key_left = 0;
	if (key == KEY_RIGHT)
		g->input.key_right = 0;
	if (key == KEY_SPACE)
		g->input.key_space = 0;
	if (key == KEY_E)
		g->input.key_e = 0;
	if (key == KEY_SHIFT)
		g->input.key_shift = 0;
	return (0);
}

void	init_input(t_input *input)
{
	input->key_w = 0;
	input->key_a = 0;
	input->key_s = 0;
	input->key_d = 0;
	input->key_up = 0;
	input->key_down = 0;
	input->key_left = 0;
	input->key_right = 0;
	input->key_space = 0;
	input->key_e = 0;
	input->key_shift = 0;
	input->key_escape = 0;
}
