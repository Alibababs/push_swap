/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:30:25 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 14:27:25 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error();
	ft_parse_args(argc, argv, &stack_a);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
