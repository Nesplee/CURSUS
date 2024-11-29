/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:06:59 by dinguyen          #+#    #+#             */
/*   Updated: 2024/11/29 19:06:51 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}		t_stack;

//	ARGUMENTS
void	quick_sort(int *arr, int low, int high);
int		*convert_arguments(int ac, char **av, int *size);
int		validate_arguments(int ac, char **av);
t_stack	*initialize_stack_a(int ac, char **av);
//	OPERATIONS 1
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
//	OPERATIONS 2
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
//	OPERATIONS 3
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
//	SORTING 1
void	sort_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
int		find_min_index(t_stack *stack);
void	push_min_to_b(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
//	UTILS ARGUMENTS 1
void	print_error_and_exit(char *message);
long	safe_atoi(const char *str);
int		has_duplicates(int *arr, int size);
int		count_words_in_args(int ac, char **av);
int		add_words_to_array(char *arg, int *arr, int index);
//	UTILS ARGUMENTS 2
int		*validate_and_convert(int ac, char **av, int *size);
t_stack	*create_stack(void);
void	fill_stack(t_stack *stack, int *values, int size);
//	UTILS OPERATIONS 1
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap_top(t_stack *stack);
void	rotate_top_to_bottom(t_stack *stack);
void	rotate_bottom_to_top(t_stack *stack);
//	UTILS STACKS 1
t_node	*create_node(int value);
t_stack	*init_stack(void);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
//	UTILS STACKS 2
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *a);

#endif
