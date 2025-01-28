/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:05:24 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/24 18:38:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_instruction(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (swap(a));
	else if (!ft_strncmp(line, "sb\n", 3))
		return (swap(b));
	else if (!ft_strncmp(line, "ss\n", 3))
		return (swap(a) && swap(b));
	else if (!ft_strncmp(line, "pa\n", 3))
		return (push(a, b));
	else if (!ft_strncmp(line, "pb\n", 3))
		return (push(b, a));
	else if (!ft_strncmp(line, "ra\n", 3))
		return (rotate_up(a));
	else if (!ft_strncmp(line, "rb\n", 3))
		return (rotate_up(b));
	else if (!ft_strncmp(line, "rr\n", 3))
		return (rotate_up(a) && rotate_up(b));
	else if (!ft_strncmp(line, "rra\n", 4))
		return (rotate_down(a));
	else if (!ft_strncmp(line, "rrb\n", 4))
		return (rotate_down(b));
	else if (!ft_strncmp(line, "rrr\n", 4))
		return (rotate_down(a) && rotate_down(b));
	return (0);
}

static int	validate_instruction(char *line)
{
	if (!line || !*line)
		return (0);
	if (line[0] == ' ' || line[ft_strlen(line) - 2] == ' ')
		return (0);
	return (1);
}

static void	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!validate_instruction(line))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			print_error_and_exit();
		}
		if (!execute_instruction(a, b, line))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			print_error_and_exit();
		}
		free(line);
		line = get_next_line(0);
	}
}

t_stack	*init_empty_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * size);
	stack->index = (int *)malloc(sizeof(int) * size);
	if (!stack->array || !stack->index)
	{
		free_stack(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2)
		return (0);
	a = validate_and_convert(ac, av);
	if (!a)
		print_error_and_exit();
	size = a->top + 1;
	b = init_empty_stack(size);
	if (!b)
	{
		free_stack(a);
		print_error_and_exit();
	}
	read_and_execute(a, b);
	if (is_sorted(a) && b->top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
