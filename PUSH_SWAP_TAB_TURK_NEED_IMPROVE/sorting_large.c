/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:42:25 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/22 00:07:12 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_chunks(t_stack *a, int *chunk_count, int *chunk_size)
{
	if (a->size <= 100)
		*chunk_count = 5;
	else
		*chunk_count = 11;
	*chunk_size = a->size / *chunk_count;
	if (a->size % *chunk_count != 0)
		(*chunk_size)++;
}

int	find_position_in_range(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (a->index[i] >= min && a->index[i] <= max)
			return (a->top - i);
		i--;
	}
	return (-1);
}

void	push_range(t_stack *a, t_stack *b, int min, int max)
{
	int	pushed;
	int	pos;
	int	target_count;

	pushed = 0;
	target_count = max - min + 1;
	while (pushed < target_count && a->top >= 0)
	{
		if (a->index[a->top] >= min && a->index[a->top] <= max)
		{
			pb(a, b);
			pushed++;
			continue ;
		}
		pos = find_position_in_range(a, min, max);
		if (pos == -1)
			break ;
		if (pos <= (a->top + 1) / 2)
			ra(a);
		else
			rra(a);
	}
}

void	push_back_sorted_chunk(t_stack *a, t_stack *b, int chunk_size)
{
	int	max_pos;
	int	top_half;
	int	first_push;
	int	pushed;

	pushed = 0;
	first_push = 1;
	while (b->top >= 0 && pushed < chunk_size)
	{
		max_pos = find_max_index(b);
		top_half = (max_pos > b->top / 2);
		while (b->index[b->top] != b->index[max_pos])
		{
			if (top_half)
				rb(b);
			else
				rrb(b);
			max_pos = find_max_index(b);
		}
		pa(a, b);
		if (first_push && a->top > 0 && a->index[a->top] > a->index[a->top - 1])
			sa(a);
		first_push = 0;
		pushed++;
	}
}
