/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:06:23 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 09:58:44 by dinguyen         ###   ########.fr       */
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
	rotate_top_to_bottom(a);
	rotate_top_to_bottom(b);
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL
		|| b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	rotate_bottom_to_top(a);
	rotate_bottom_to_top(b);
	ft_printf("rrr\n");
}
