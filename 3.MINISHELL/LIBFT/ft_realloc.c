/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:56:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/07 09:56:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *old, size_t old_size, size_t new_size)
{
	char	*new;
	size_t	i;

	new = malloc(new_size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_size && i < new_size - 1)
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
	free(old);
	return (new);
}
