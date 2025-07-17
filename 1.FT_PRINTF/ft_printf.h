/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:28:18 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/15 14:38:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_puthex(unsigned long num, int uppercase);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
