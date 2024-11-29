/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:06:17 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 11:31:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	swap_top(b);
	ft_printf("sb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b == NULL || b->top == NULL)
		return ;
	push (a, pop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
}
