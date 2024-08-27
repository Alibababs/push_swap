/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:52:01 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 21:52:03 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	if (*stack_a && ft_stack_size(*stack_a) < 2)
		return ;
	ft_rotate(stack_a);
	ft_printf("%s", "ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2)
		return ;
	ft_rotate(stack_b);
	ft_printf("%s", "rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b && ft_stack_size(*stack_b) < 2)
		&& (*stack_a && ft_stack_size(*stack_a) < 2))
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("%s", "rr\n");
}


void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	*stack = (*stack)->next;
	temp->next->next = NULL;
}
