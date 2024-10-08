/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:31:36 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 00:22:57 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_large_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_divide_and_move(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_move_element_to_a(stack_a, stack_b);
		while (ft_get_tail_index(*stack_a) == (*stack_a)->index - 1)
			ft_rra(stack_a);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
	{
		ft_sort_two(stack_a);
		return ;
	}
	else if (size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	else
		handle_large_sort(stack_a, stack_b);
}
