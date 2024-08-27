/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:31:22 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 20:31:26 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	if (first->value > second->value)
		ft_sa(stack);
}

void	handle_sorting_cases(t_stack **stack, t_stack *first,
		t_stack *second, t_stack *third)
{
	if (first->value > second->value && first->value > third->value)
	{
		ft_ra(stack);
		if (second->value > third->value)
			ft_sa(stack);
		return ;
	}
	if (second->value > first->value && first->value > third->value)
	{
		ft_rra(stack);
		return ;
	}
	if (second->value > first->value && second->value > third->value)
	{
		ft_sa(stack);
		ft_ra(stack);
		return ;
	}
	if (third->value > first->value && third->value > second->value)
	{
		if (first->value > second->value)
			ft_sa(stack);
		return ;
	}
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	if (ft_is_sorted(*stack))
		return ;
	handle_sorting_cases(stack, first, second, third);
}
