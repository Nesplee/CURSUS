/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:55:36 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/30 14:57:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack, int value)
{
	t_node	*node;

	node = create_node(value);
	if (node == NULL)
		return (0);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
	return (1);
}

int	pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (stack->top == NULL)
		return (0);
	node = stack->top;
	value = node->value;
	stack->top = node->next;
	free(node);
	stack->size--;
	return (value);
}

int	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->top == NULL)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	return (1);
}

int	rotate_top_to_bottom(t_stack *stack)
{
	t_node	*first;
	t_node	*current;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return (0);
	first = stack->top;
	stack->top = first->next;
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
	return (1);
}

int	rotate_bottom_to_top(t_stack *stack)
{
	t_node	*last;
	t_node	*current;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return (0);
	last = NULL;
	current = stack->top;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	if (last != NULL)
		last->next = NULL;
	current->next = stack->top;
	stack->top = current;
	return (1);
}
