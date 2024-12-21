/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:07 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/20 02:18:34 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_elements(char **split_args)
{
	int	count;

	count = 0;
	while (split_args[count])
		count++;
	return (count);
}

static char	**get_split_args(int ac, char **av)
{
	char	*joined_args;
	char	**split_args;

	joined_args = join_arguments(ac, av);
	split_args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!split_args)
		print_error_and_exit();
	return (split_args);
}

static int	*validate_numbers(char **split_args, int size)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		print_error_and_exit();
	i = 0;
	while (i < size)
	{
		if (!ft_isnumber(split_args[i]))
		{
			free(numbers);
			print_error_and_exit();
		}
		numbers[i] = (int)safe_atoi(split_args[i]);
		i++;
	}
	has_duplicates(numbers, size);
	return (numbers);
}

static void	fill_stack(t_stack *stack, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack->array[i] = numbers[size - 1 - i];
		stack->top = i;
		i++;
	}
}

t_stack	*validate_and_convert(int ac, char **av)
{
	t_stack	*stack_a;
	char	**split_args;
	int		*numbers;
	int		size;

	split_args = get_split_args(ac, av);
	size = count_elements(split_args);
	numbers = validate_numbers(split_args, size);
	ft_split_free(split_args);
	stack_a = init_stack(size);
	if (!stack_a)
	{
		free(numbers);
		print_error_and_exit();
	}
	fill_stack(stack_a, numbers, size);
	free(numbers);
	return (stack_a);
}
