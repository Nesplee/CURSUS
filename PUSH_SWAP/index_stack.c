/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:38:58 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/22 04:17:29 by dinguyen         ###   ########.fr       */
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
	stack->index = malloc(sizeof(int) * size);
	if (!stack->index)
	{
		free(stack->array);
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				ft_swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

static int	find_position(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	copy_array(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	index_stack(t_stack *stack)
{
	int	*temp;
	int	i;
	int	size;

	if (!stack)
		return ;
	size = stack->top + 1;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return ;
	copy_array(temp, stack->array, size);
	sort_array(temp, size);
	i = 0;
	while (i < size)
	{
		stack->index[i] = find_position(stack->array[i], temp, size);
		i++;
	}
	free(temp);
}
