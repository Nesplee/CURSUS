/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:22:43 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/24 13:10:23 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cbrt(int n)
{
	int	i;

	i = 1;
	while (i * i * i <= n)
		i++;
	return (i - 1);
}

static int	ft_log2(int n)
{
	int	count;

	count = 0;
	while (n > 1)
	{
		n /= 2;
		count++;
	}
	return (count);
}

void	calculate_chunks(t_stack *a, int *chunk_count, int *chunk_size)
{
	int	size;
	int	optimal_chunks;

	size = a->top + 1;
	if (size <= 100)
	{
		optimal_chunks = ft_cbrt(size) * 2;
		if (optimal_chunks < 4)
			optimal_chunks = 4;
		else if (optimal_chunks > 6)
			optimal_chunks = 6;
	}
	else
	{
		optimal_chunks = ft_log2(size) * 1.5;
		if (optimal_chunks < 8)
			optimal_chunks = 8;
		else if (optimal_chunks > 12)
			optimal_chunks = 12;
	}
	*chunk_count = optimal_chunks;
	*chunk_size = size / optimal_chunks;
	if (size % optimal_chunks)
		(*chunk_size)++;
}

