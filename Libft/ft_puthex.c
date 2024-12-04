/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:01:10 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/27 11:35:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long num, int uppercase)
{
	char	hex[16];
	char	*base;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (uppercase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num == 0)
		return (ft_putchar('0'));
	while (num > 0)
	{
		hex[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		count = count + ft_putchar(hex[i]);
	}
	return (count);
}
