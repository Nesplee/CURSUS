/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verifications2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:34:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/30 14:34:44 by dinguyen         ###   ########.fr       */
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

static int	*allocate_and_convert(char **split_args, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		print_error_and_exit("Erreur d'allocation");
	i = 0;
	while (i < size)
	{
		if (!ft_isnumber(split_args[i]))
			print_error_and_exit("Arguments non valides");
		arr[i] = (int)safe_atoi(split_args[i]);
		free(split_args[i]);
		i++;
	}
	return (arr);
}

int	*validate_and_convert(int ac, char **av, int *size)
{
	char	*joined_args;
	char	**split_args;
	int		*arr;

	joined_args = join_arguments(ac, av);
	split_args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!split_args)
		print_error_and_exit("Erreur lors du split");
	*size = count_elements(split_args);
	arr = allocate_and_convert(split_args, *size);
	free(split_args);
	has_duplicates(arr, *size);
	return (arr);
}
