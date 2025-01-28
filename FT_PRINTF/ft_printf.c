/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:54:14 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/18 17:13:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_return(const char specifier, va_list args, int *count)
{
	if (specifier == 'c')
		*count = *count + ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		*count = *count + ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		*count = *count + ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		*count = *count + ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		*count = *count + ft_puthex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		*count = *count + ft_puthex(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
		*count = *count + ft_putptr(va_arg(args, void *));
	else if (specifier == '%')
		*count = *count + ft_putchar('%');
	else
		*count = *count + ft_putchar(specifier);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				format_return(format[i], args, &count);
			else
				count = count + ft_putchar('%');
		}
		else
			count = count + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
