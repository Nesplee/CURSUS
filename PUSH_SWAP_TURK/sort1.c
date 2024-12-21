/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:30:12 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/21 18:33:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (!a || a->top < 1)
		return ;
	top = a->array[a->top];
	mid = a->array[a->top - 1];
	bot = a->array[0];
	if (top > mid && mid < bot && bot < top)
		ra(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		rra(a);
		sa(a);
	}
	else if (top > mid && mid < bot && bot > mid)
		sa(a);
	else if (top > bot && mid > bot)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	if (!a || a->top < 4)
		return ;
	size = a->top + 1;
	while (size > 3)
	{
		min_pos = find_min_index(a);
		while (min_pos != a->top)
		{
			if (min_pos > a->top / 2)
				ra(a);
			else
				rra(a);
			min_pos = find_min_index(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (b->top >= 0)
		pa(a, b);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	initial_size;

	if (!a || !b || a->top < 3)
		return ;
	if (is_sorted(a))
		return ;
	initial_size = a->top + 1;
	split_until_three(a, b);
	sort_three(a);
	push_back_sorted_chunk(a, b, initial_size - 3);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (is_sorted(a))
		return ;
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}
