/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:31:51 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 17:46:00 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushlst(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		ft_free_stack(stack);
		ft_error();
	}
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	ft_assign_indexes(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		index;

	current = *stack_a;
	while (current)
	{
		tmp = *stack_a;
		index = 0;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	ft_get_tail_index(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}
