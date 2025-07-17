/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:48:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/04 16:21:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*last;

	if (lst == NULL || new_elem == NULL)
		return ;
	if (lst[0] == NULL)
	{
		lst[0] = new_elem;
		return ;
	}
	last = ft_lstlast(lst[0]);
	last->next = new_elem;
}
