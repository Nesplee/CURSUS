/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:37:31 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/19 16:29:51 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
