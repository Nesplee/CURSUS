/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:25:08 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:15:26 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] <= pivot)
				ft_swap(&arr[++i], &arr[j]);
			j++;
		}
		ft_swap(&arr[i + 1], &arr[high]);
		quick_sort(arr, low, i);
		quick_sort(arr, i + 2, high);
	}
}


t_stack	*initialize_stack_a(int ac, char **av)
{
	t_stack	*stack_a;
	int		*values;
	int		size;
	int		i;

	values = validate_and_convert(ac, av, &size);
	if (!values)
		return (NULL);
	stack_a = create_stack();
	if (!stack_a)
		print_error_and_exit("Erreur d'allocation pour la pile");
	i = size - 1; // Ajoute les éléments en partant de la fin
	while (i >= 0)
	{
		push(stack_a, values[i]);
		i--;
	}
	free(values);
	return (stack_a);
}
