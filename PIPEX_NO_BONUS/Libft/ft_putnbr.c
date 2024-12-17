/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:51:37 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/27 11:35:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	count;
	int	r;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		count++;
	}
	if (n > 9)
		count = count + ft_putnbr(n / 10);
	r = (n % 10) + '0';
	ft_putchar(r);
	count++;
	return (count);
}
