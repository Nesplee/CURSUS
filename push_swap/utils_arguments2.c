/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arguments2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:31:41 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:55:43 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*validate_and_convert(int ac, char **av, int *size)
{
	int	*values;
	int	index;
	int	i;

	if (ac < 2)
		print_error_and_exit("Pas assez d'arguments");
	*size = count_words_in_args(ac, av);
	values = malloc(sizeof(int) * (*size));
	if (!values)
		print_error_and_exit("Erreur d'allocation");
	index = 0;
	i = 0;
	while (i < ac)
	{
		index = add_words_to_array(av[i], values, index);
		i++;
	}
	has_duplicates(values, *size);
	return (values);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		print_error_and_exit("Error: Stack allocation failed");
	return (stack);
}

