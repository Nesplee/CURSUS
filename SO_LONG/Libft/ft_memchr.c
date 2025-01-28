/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:06:18 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/04 00:31:12 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		ch;

	i = 0;
	source = (const unsigned char *)s;
	ch = (unsigned char )c;
	while (i < n)
	{
		if (source[i] == ch)
			return ((void *)&source[i]);
		i++;
	}
	return (NULL);
}
