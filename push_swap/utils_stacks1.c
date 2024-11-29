/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:28:26 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:06:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
	{
		ft_printf("La pile est vide.\n");
		return ;
	}
	current = stack->top;
	ft_printf("Pile:");
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	if (stack == NULL)
		return ;
	node = stack->top;
	while (node != NULL)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(stack);
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*node;

	if (stack == NULL || stack->top == NULL)
		return (0);
	i = 0;
	node = stack->top;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}
