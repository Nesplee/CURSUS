/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:37:40 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/04 00:08:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	buffer = malloc(total_size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}
