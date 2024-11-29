/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:06:21 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 11:08:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	rotate_top_to_bottom(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	rotate_top_to_bottom(b);
	ft_printf("rb\n");
}

void	rra(t_stack *a)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	rotate_bottom_to_top(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	rotate_bottom_to_top(b);
	ft_printf("rrb\n");
}
