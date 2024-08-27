/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:52:06 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 21:52:07 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	if (*stack_a && ft_stack_size(*stack_a) < 2)
		return ;
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2)
		return ;
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && ft_stack_size(*stack_a) < 2)
		&& (*stack_b && ft_stack_size(*stack_b) < 2))
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	ft_swap(t_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	temp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = temp;
}
