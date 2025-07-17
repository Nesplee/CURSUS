/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:45:46 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/19 15:48:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (rotate_up(a))
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate_up(b))
		ft_printf("rb\n");
}

void	rra(t_stack *a)
{
	if (rotate_down(a))
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (rotate_down(b))
		ft_printf("rrb\n");
}
