/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:42:25 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/25 20:19:43 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_in_range(t_stack *stack, int min, int max)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->index[i] >= min && stack->index[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

static int	find_shortest_path(t_stack *stack, int pos)
{
	int	up_moves;
	int	down_moves;

	if (!stack || pos < 0 || pos > stack->top)
		return (0);
	up_moves = stack->top - pos;
	down_moves = pos + 1;
	if (up_moves <= down_moves)
		return (up_moves);
	return (-down_moves);
}

static void	handle_push_rotate(t_stack *a, t_stack *b, t_range *r)
{
	int	next_pos;

	pb(a, b);
	next_pos = find_next_in_range(a, r->min, r->max);
	if (b->top > 0 && b->index[b->top] > r->mid)
	{
		if (next_pos != -1 && next_pos != a->top
			&& find_shortest_path(a, next_pos) > 0)
			rr(a, b);
		else
			rb(b);
	}
}

static void	handle_rotation(t_stack *a, int pos)
{
	int	moves;

	moves = find_shortest_path(a, pos);
	if (moves > 0)
		while (moves--)
			ra(a);
	else
		while (moves++)
			rra(a);
}

void	push_range(t_stack *a, t_stack *b, int min, int max)
{
	int		pos;
	t_range	r;

	r.min = min;
	r.max = max;
	r.mid = min + ((max - min) / 2);
	pos = find_next_in_range(a, r.min, r.max);
	while (pos != -1)
	{
		if (pos == a->top)
			handle_push_rotate(a, b, &r);
		else
			handle_rotation(a, pos);
		pos = find_next_in_range(a, r.min, r.max);
	}
}
