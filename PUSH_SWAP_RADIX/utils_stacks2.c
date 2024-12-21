/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:24:23 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/02 17:05:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (1);
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (a == NULL || a->top == NULL)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	print_stack(const char *msg, t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	ft_printf("%s: ", msg);
	current = stack->top;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

int	find_min_index(t_stack *stack)
{
	int		index;
	int		min_index;
	int		min_value;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (-1);
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

int	find_max_index(t_stack *stack)
{
	int		index;
	int		max_index;
	int		max_value;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (-1);
	index = 0;
	max_index = 0;
	max_value = stack->top->value;
	current = stack->top;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}
