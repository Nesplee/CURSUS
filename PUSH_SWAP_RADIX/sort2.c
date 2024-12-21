/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:09:05 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/05 12:11:08 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_stack *a, int *offset)
{
	int		min;
	t_node	*current;

	if (!a || is_empty(a))
		return ;
	current = a->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	*offset = -min;
	current = a->top;
	while (current)
	{
		current->value += *offset;
		current = current->next;
	}
}

void	restore_stack(t_stack *a, int offset)
{
	t_node	*current;

	if (!a || is_empty(a))
		return ;
	current = a->top;
	while (current)
	{
		current->value -= offset;
		current = current->next;
	}
}

void	process_bit(t_stack *a, t_stack *b, int bit, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (((a->top->value >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
	}
	while (!is_empty(b))
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	size;
	int	max_bits;
	int	offset;

	if (!a || !b || is_sorted(a))
		return ;
	normalize_stack(a, &offset);
	size = stack_size(a);
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, size);
		bit++;
	}
	restore_stack(a, offset);
}
