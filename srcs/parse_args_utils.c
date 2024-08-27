/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:30:03 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 23:04:58 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

bool	ft_str_is_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_is_whitespace(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_is_valid_int(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_is_int_range(const char *str)
{
	long	value;

	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (false);
	return (true);
}

bool	ft_has_duplicates(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}
