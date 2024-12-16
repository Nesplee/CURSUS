/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:09:50 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/15 02:13:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)ptr;
	count = count + ft_putstr("0x");
	if (address == 0)
		count = count + ft_putchar('0');
	else
		count = count + ft_puthex(address, 0);
	return (count);
}
