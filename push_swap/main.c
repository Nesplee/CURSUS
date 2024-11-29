/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:09:20 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:07:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = initialize_stack_a(ac - 1, av + 1);
	if (!a)
		print_error_and_exit("Initialization failed");
	b = init_stack();
	if (!b)
	{
		free_stack(a);
		print_error_and_exit("Stack allocation failed");
	}
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
