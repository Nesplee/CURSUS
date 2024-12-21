/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:00:28 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/21 18:32:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int		tmp;

	if (stack->top >= 1)
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
		return (1);
	}
	return (0);
}

int	push(t_stack *dest, t_stack *src)
{
	if (src->top >= 0 && dest->top < dest->size -1)
	{
		dest->top++;
		dest->array[dest->top] = src->array[src->top];
		src->top--;
		return (1);
	}
	return (0);
}

//	ROTATE_TOP_TO_BOTTOM
int	rotate_up(t_stack *stack)
{
	int		tmp;
	int		i;

	if (stack->top < 1)
		return (0);
	tmp = stack->array[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
	return (1);
}

//	ROTATE_BOTTOM_TO_TOP
int	rotate_down(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top < 1)
		return (0);
	tmp = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
	return (1);
}
