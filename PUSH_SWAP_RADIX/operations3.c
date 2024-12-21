/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:52:51 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/01 15:22:40 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL
		|| b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL
		|| b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL
		|| b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
