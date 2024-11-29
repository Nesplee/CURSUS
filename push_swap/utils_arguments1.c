/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arguments1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:36:10 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 11:45:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

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
			print_error_and_exit("Valeur inférieure à INT_MIN");
		if (num * sign > INT_MAX)
			print_error_and_exit("Valeur supérieure à INT_MAX");
		str++;
	}
	return (num * sign);
}

int	has_duplicates(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			print_error_and_exit("Doublons détectés");
		i++;
	}
	return (0);
}

int	count_words_in_args(int ac, char **av)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < ac)
	{
		count = count + count_words(av[i], ' ');
		i++;
	}
	return (count);
}

int	add_words_to_array(char *arg, int *arr, int index)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		print_error_and_exit("le Split n'a pas fonctionné\n");
	j = 0;
	while (split[j])
	{
		arr[index++] = (int)safe_atoi(split[j]);
		free(split[j]);
		j++;
	}
	free(split);
	return (index);
}
