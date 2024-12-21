/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:46:56 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/04 12:03:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	if (swap_top(a))
		ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	if (swap_top(b))
		ft_printf("sb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b == NULL || b->top == NULL)
		return ;
	if (push(a, pop(b)))
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL)
		return ;
	if (push(b, pop(a)))
		ft_printf("pb\n");
}
