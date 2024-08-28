/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:13 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 14:32:14 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruction;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	ft_parse_args(argc, argv, &stack_a);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		execute_instruction(instruction, &stack_a, &stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (ft_is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
