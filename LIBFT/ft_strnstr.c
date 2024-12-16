/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:01:08 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/07 19:36:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	j = 0;
	little_len = 0;
	if (*little == '\0')
		return ((char *)big);
	while (little[little_len])
		little_len++;
	while (big[j] && (j + little_len) <= len)
	{
		i = 0;
		while (i < little_len && big[j + i] == little[i])
			i++;
		if (i == little_len)
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}
