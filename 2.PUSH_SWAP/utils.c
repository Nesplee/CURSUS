/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:00:58 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/25 22:01:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		if (stack->index)
			free(stack->index);
		free(stack);
	}
}

void	print_error_and_exit(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->top < 0)
		return (0);
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

//	INUTILISEE
int	find_max_index(t_stack *stack)
{
	int	i;
	int	max_index;
	int	max_value;

	if (stack->top < 0)
		return (-1);
	max_index = 0;
	max_value = stack->array[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] > max_value)
		{
			max_value = stack->array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	if (stack->top < 0)
		return (-1);
	min_index = 0;
	min_value = stack->array[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] < min_value)
		{
			min_value = stack->array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
