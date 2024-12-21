/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:33:50 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/05 11:14:26 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	if (!a || !b || is_sorted(a))
		return ;
	size = stack_size(a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(a) != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

t_stack	*initialize_stack_a(int ac, char **av)
{
	t_stack	*stack_a;
	int		*values;
	int		size;
	int		i;

	values = validate_and_convert(ac, av, &size);
	if (!values)
		return (NULL);
	stack_a = init_stack();
	if (!stack_a)
		print_error_and_exit("Erreur d'allocation pour la pile");
	i = size - 1;
	while (i >= 0)
	{
		push(stack_a, values[i]);
		i--;
	}
	free(values);
	return (stack_a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	size;
	int	min_index;

	size = stack_size(a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
	{
		while (size > 3)
		{
			min_index = find_min_index(a);
			if (min_index == 0)
				pb(a, b);
			else if (min_index <= size / 2)
				ra(a);
			else
				rra(a);
			size = stack_size(a);
		}
		sort_three(a);
		while (!is_empty(b))
			pa(a, b);
	}
}
