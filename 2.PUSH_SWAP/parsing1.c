/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:05:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/24 16:37:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	safe_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num * sign < INT_MIN)
			print_error_and_exit();
		if (num * sign > INT_MAX)
			print_error_and_exit();
		str++;
	}
	return (num * sign);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				print_error_and_exit();
			j++;
		}
		i++;
	}
	return (0);
}

int	count_elements(char **split_args)
{
	int	count;

	count = 0;
	while (split_args[count])
		count++;
	return (count);
}

int	*validate_numbers(char **split_args, int size)
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

void	fill_stack(t_stack *stack, int *numbers, int size)
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
