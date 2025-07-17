/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:00:28 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/22 00:07:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (stack->top >= 1)
	{
		tmp_val = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp_val;
		tmp_idx = stack->index[stack->top];
		stack->index[stack->top] = stack->index[stack->top - 1];
		stack->index[stack->top - 1] = tmp_idx;
		return (1);
	}
	return (0);
}

int	push(t_stack *dest, t_stack *src)
{
	if (src->top >= 0 && dest->top < dest->size - 1)
	{
		dest->top++;
		dest->array[dest->top] = src->array[src->top];
		dest->index[dest->top] = src->index[src->top];
		src->top--;
		return (1);
	}
	return (0);
}

int	rotate_up(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;
	int	i;

	if (stack->top < 1)
		return (0);
	tmp_val = stack->array[stack->top];
	tmp_idx = stack->index[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		stack->index[i] = stack->index[i - 1];
		i--;
	}
	stack->array[0] = tmp_val;
	stack->index[0] = tmp_idx;
	return (1);
}

int	rotate_down(t_stack *stack)
{
	int	tmp_val;
	int	tmp_idx;
	int	i;

	if (stack->top < 1)
		return (0);
	tmp_val = stack->array[0];
	tmp_idx = stack->index[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp_val;
	stack->index[stack->top] = tmp_idx;
	return (1);
}
