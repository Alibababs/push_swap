/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:31:29 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 20:31:32 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_find_index(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
