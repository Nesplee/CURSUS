/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:42:25 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/24 13:23:12 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_in_range(t_stack *stack, int min, int max)
{
	int	i;
	int	j;

	i = stack->top;
	j = 0;
	while (i >= j)
	{
		if (stack->index[i] >= min && stack->index[i] <= max)
			return (i);
		if (stack->index[j] >= min && stack->index[j] <= max)
			return (j);
		i--;
		j++;
	}
	return (-1);
}

static int	count_elements_in_range(t_stack *stack, int min, int max)
{
	int	i;
	int	count;

	i = stack->top;
	count = 0;
	while (i >= 0)
	{
		if (stack->index[i] >= min && stack->index[i] <= max)
			count++;
		i--;
	}
	return (count);
}

void	push_range(t_stack *a, t_stack *b, int min, int max)
{
	int	target_count;
	int	pushed;
	int	pos;
	int	mid;

	pushed = 0;
	mid = min + ((max - min) / 2);
	target_count = count_elements_in_range(a, min, max);
	while (pushed < target_count)
	{
		pos = find_next_in_range(a, min, max);
		if (pos == -1)
			break ;
		if (pos == a->top)
		{
			pb(a, b);
			if (b->top > 0 && b->index[b->top] > mid)
				rb(b);
			pushed++;
		}
		else if (pos > a->top / 2)
			ra(a);
		else
			rra(a);
	}
}
