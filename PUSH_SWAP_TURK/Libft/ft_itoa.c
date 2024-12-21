/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:03:17 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/05 17:44:44 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_buffer(char buffer[], int length)
{
	int		st;
	int		en;
	char	temp;

	st = 0;
	en = length - 1;
	while (st < en)
	{
		temp = buffer[st];
		buffer[st] = buffer[en];
		buffer[en] = temp;
		st++;
		en--;
	}
}

static int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *str, long num, int len)
{
	int	i;

	i = 0;
	if (num == 0)
		str[i++] = '0';
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	if (str[0] == '-')
		reverse_buffer(str + 1, len - 1);
	else
		reverse_buffer(str, len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = get_num_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	fill_string(str, num, len);
	return (str);
}
