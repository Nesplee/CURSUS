/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:03:07 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/03 23:42:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*last_occurence;

	ch = (char)c;
	last_occurence = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			last_occurence = (char *)(s + i);
		i++;
	}
	if (s[i] == ch)
		last_occurence = (char *)(s + i);
	return (last_occurence);
}
