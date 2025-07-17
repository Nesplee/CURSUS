/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:07 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/25 18:09:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_from_numbers(int *numbers, int size)
{
	t_stack	*stack_a;

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

t_stack	*validate_and_convert(int ac, char **av)
{
	char	**split_args;
	int		*numbers;
	int		size;

	if (ac == 2)
	{
		split_args = ft_split(av[1], ' ');
		if (!split_args)
			print_error_and_exit();
		size = count_elements(split_args);
	}
	else
	{
		split_args = &av[1];
		size = ac - 1;
	}
	numbers = validate_numbers(split_args, size);
	if (ac == 2)
		ft_split_free(split_args);
	return (create_stack_from_numbers(numbers, size));
}
