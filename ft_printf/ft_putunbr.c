/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:55:22 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/15 01:58:48 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	r;

	count = 0;
	if (n > 9)
		count = count + ft_putunbr(n / 10);
	r = (n % 10) + '0';
	ft_putchar(r);
	count++;
	return (count);
}
