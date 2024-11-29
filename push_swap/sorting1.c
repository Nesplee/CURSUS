/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:00:58 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:07:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(a) != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (stack_size(a) <= 3)
		sort_three(a);
	else if (stack_size(a) <= 5)
		sort_five(a, b);
	else
		print_error_and_exit("too long\n");
}

int	find_min_index(t_stack *stack)
{
	int		index;
	int		min_index;
	int		min_value;
	t_node	*current;

	index = 0;
	min_index = 0;
	min_value = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		index++;
		current = current->next;
	}
	return (min_index);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index <= a->size / 2)
	{
		while (min_index--)
			ra(a);
	}
	else
	{
		min_index = a->size - min_index;
		while (min_index--)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (stack_size(a) != 5)
		return ;
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
