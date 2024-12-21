/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:47:33 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/05 11:27:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

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
//	OPERATIONS 4
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		swap_top(t_stack *stack);
int		rotate_top_to_bottom(t_stack *stack);
int		rotate_bottom_to_top(t_stack *stack);
//	SORT 1
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
t_stack	*initialize_stack_a(int ac, char **av);
void	sort_small(t_stack *a, t_stack *b);
//	SORT 2
void	radix_sort(t_stack *a, t_stack *b);
//	UTILS STACKS 1
t_node	*create_node(int value);
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
void	print_error_and_exit(char *message);
//	UTILS STACKS 2
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *a);
void	print_stack(const char *msg, t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
//	UTILS VERIFICATIONS 1
long	safe_atoi(const char *str);
int		has_duplicates(int *arr, int size);
int		count_words_in_args(int ac, char **av);
char	*join_arguments(int ac, char **av);
//	UTILS VERIFICATIONS 2
int		*validate_and_convert(int ac, char **av, int *size);

#endif
