/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:48:23 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/15 01:51:15 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	if (str == NULL)
		str = "(NULL)";
	i = 0;
	count = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}
