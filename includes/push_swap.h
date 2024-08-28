/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:31:07 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 14:24:13 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;

}					t_stack;

void				ft_error(void);
void				ft_pushlst(t_stack **stack, int value);
void				ft_assign_indexes(t_stack **stack_a);
void				ft_free_stack(t_stack **stack);
void				ft_parse_args(int argc, char *argv[], t_stack **stack_a);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
int					ft_stack_size(t_stack *stack);
int					ft_get_tail_index(t_stack *stack);

/* SORT */

bool				ft_is_sorted(t_stack *stack);
int					ft_find_index(t_stack *stack, int target);
void				ft_sort_two(t_stack **stack);
void				ft_sort_three(t_stack **stack);
void				ft_partition_and_move(t_stack **stack_a, t_stack **stack_b,
						int pv1, int pv2);
void				ft_divide_and_move(t_stack **stack_a, t_stack **stack_b);
void				ft_move_element_to_a(t_stack **stack_a, t_stack **stack_b);
void				ft_move_top_elements_to_a(t_stack **stack_a,
						t_stack **stack_b, int last_idx_a);
void				ft_move_bottom_elements_to_a(t_stack **stack_a,
						t_stack **stack_b);

/* PARSING */

bool				ft_is_valid_int(const char *str);
bool				ft_is_int_range(const char *str);
bool				ft_has_duplicates(t_stack *stack, int value);
bool				ft_str_is_whitespace(const char *str);

/* OPERATIONS */

void				ft_push(t_stack **from_stack, t_stack **to_stack);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

void				ft_swap(t_stack **stack);
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

void				ft_rotate(t_stack **stack);
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

void				ft_reverse_rotate(t_stack **stack);
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

/* CHECKER */

int		execute_swap_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_push_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_rotate_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
int		execute_reverse_instructions(char *instruction,
			t_stack **stack_a, t_stack **stack_b);
void	execute_instruction(char *instruction,
			t_stack **stack_a, t_stack **stack_b);

#endif