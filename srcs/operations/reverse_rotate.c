/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:51:53 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 21:51:56 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack **stack_a)
{
	if (*stack_a && ft_stack_size(*stack_a) < 2)
		return ;
	ft_reverse_rotate(stack_a);
	ft_printf("%s", "rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	if (*stack_b && ft_stack_size(*stack_b) < 2)
		return ;
	ft_reverse_rotate(stack_b);
	ft_printf("%s", "rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && ft_stack_size(*stack_a) < 2)
		&& (*stack_b && ft_stack_size(*stack_b) < 2))
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("%s", "rrr\n");
}
