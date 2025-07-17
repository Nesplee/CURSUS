/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:49:48 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/19 15:54:46 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) && swap(b))
		ft_printf("ss\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (rotate_up(a) && rotate_up(b))
		ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (rotate_down(a) && rotate_down(b))
		ft_printf("rrr\n");
}
