/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:05:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/19 16:34:17 by dinguyen         ###   ########.fr       */
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

int	count_words_in_args(int ac, char **av)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (i < ac)
	{
		count = count + count_words(av[i], ' ');
		i++;
	}
	return (count);
}

static char	*concat_with_space(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	if (!temp)
		print_error_and_exit();
	return (temp);
}

char	*join_arguments(int ac, char **av)
{
	char	*joined;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		print_error_and_exit();
	i = 1;
	while (i < ac)
	{
		joined = concat_with_space(joined, av[i]);
		if (i < ac - 1)
			joined = concat_with_space(joined, " ");
		i++;
	}
	return (joined);
}
