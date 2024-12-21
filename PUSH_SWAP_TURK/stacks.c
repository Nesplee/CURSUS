/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:42:25 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/21 18:31:57 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * size);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

static void	copy_and_sort(int *dest, int *src, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (dest[i] > dest[j])
				ft_swap(&dest[i], &dest[j]);
			j++;
		}
		i++;
	}
}

int	find_median(int *array, int len)
{
	int	*tmp;
	int	median;

	if (!array || len <= 0)
		return (0);
	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		return (0);
	copy_and_sort(tmp, array, len);
	median = tmp[len / 2];
	free(tmp);
	return (median);
}

void	split_until_three(t_stack *a, t_stack *b)
{
	int	median;
	int	i;
	int	size;

	while (a->top + 1 > 3)
	{
		size = a->top + 1;
		median = find_median(a->array, size);
		i = 0;
		while (i < size && a->top + 1 > 3)
		{
			if (a->array[a->top] < median)
				pb(a, b);
			else
				ra(a);
			i++;
		}
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
		while (b->array[b->top] != b->array[max_pos])
		{
			if (top_half)
				rb(b);
			else
				rrb(b);
			max_pos = find_max_index(b);
		}
		pa(a, b);
		if (first_push && a->top > 0 && a->array[a->top] > a->array[a->top - 1])
			sa(a);
		first_push = 0;
		pushed++;
	}
}
