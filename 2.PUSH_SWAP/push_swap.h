/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:57:20 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/25 18:09:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	int		*array;
	int		size;
	int		top;
	int		*index;
}		t_stack;

typedef struct s_range
{
	int	min;
	int	max;
	int	mid;
}	t_range;

//	INDEX STACK
t_stack		*init_stack(int size);
void		index_stack(t_stack *stack);
//	OPERATIONS 1
int			swap(t_stack *stack);
int			push(t_stack *dest, t_stack *src);
int			rotate_up(t_stack *stack);
int			rotate_down(t_stack *stack);
//	OPERATIONS 2
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
//	OPERATIONS 3
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
//	OPERATIONS 4
void		ss(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
//	PARSING 1
long		safe_atoi(const char *str);
int			has_duplicates(int *arr, int size);
int			count_elements(char **split_args);
int			*validate_numbers(char **split_args, int size);
void		fill_stack(t_stack *stack, int *numbers, int size);
//	PARSING 2
t_stack		*validate_and_convert(int ac, char **av);
//	SORTING FUNCTIONS
void		sort_three(t_stack *stack);
void		sort_five(t_stack *a, t_stack *b);
void		my_turk_sort(t_stack *a, t_stack *b);
void		sort_stack(t_stack *a, t_stack *b);
//	SORTING LARGE
void		calculate_chunks(t_stack *a, int *chunk_count, int *chunk_size);
void		push_back_sorted_chunk(t_stack *a, t_stack *b, int chunk_size);
//	SORTING LARGE 2
void		push_range(t_stack *a, t_stack *b, int min, int max);
//	UTILS
void		free_stack(t_stack *stack);
void		print_error_and_exit(void);
int			is_sorted(t_stack *stack);
int			find_max_index(t_stack *stack);
int			find_min_index(t_stack *stack);

#endif
