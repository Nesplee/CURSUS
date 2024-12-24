/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:22:43 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/24 16:22:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_chunks(t_stack *a, int *chunk_count, int *chunk_size)
{
	int	size;

	size = a->top + 1;
	if (size <= 100)
		*chunk_count = 5;
	else
		*chunk_count = 9;
	*chunk_size = size / *chunk_count;
	if (size % *chunk_count)
		(*chunk_size)++;
}

static int	find_max_position(t_stack *stack)
{
	int	i;
	int	max_pos;

	i = stack->top;
	max_pos = stack->top;
	while (i >= 0)
	{
		if (stack->index[i] > stack->index[max_pos])
			max_pos = i;
		i--;
	}
	return (max_pos);
}

void	push_back_sorted_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	max_pos;

	pushed = 0;
	while (pushed < chunk_size && b->top >= 0)
	{
		max_pos = find_max_position(b);
		if (max_pos == b->top)
		{
			pa(a, b);
			pushed++;
		}
		else if (max_pos == b->top - 1)
		{
			sb(b);
			pa(a, b);
			pushed++;
		}
		else if (max_pos > b->top / 2)
			rb(b);
		else
			rrb(b);
	}
}
