/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:44:55 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/25 18:09:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = validate_and_convert(ac, av);
	if (!a)
		return (1);
	index_stack(a);
	b = init_stack(a->size);
	if (!b)
	{
		free_stack(a);
		print_error_and_exit();
	}
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
