/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:30:12 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/27 22:46:19 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_to_stack(char *token, t_stack **stack_a)
{
	int	value;

	if (!token || *token == '\0')
		ft_error();
	if (ft_is_valid_int(token) && ft_is_int_range(token))
	{
		value = ft_atoi(token);
		if (!ft_has_duplicates(*stack_a, value))
			ft_pushlst(stack_a, value);
		else
			ft_error();
	}
	else
		ft_error();
}

static void	ft_handle_token(char *arg, t_stack **stack_a)
{
	char	**tokens;
	int		j;
	int		i;

	if (!arg || !*arg)
		ft_error();
	if (ft_str_is_whitespace(arg))
		ft_error();
	tokens = ft_split(arg, ' ');
	if (tokens != NULL)
	{
		j = -1;
		while (tokens[++j] != NULL)
			ft_add_to_stack(tokens[j], stack_a);
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
}

void	ft_parse_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;

	i = 0;
	while (++i < argc)
		ft_handle_token(argv[i], stack_a);
	ft_assign_indexes(stack_a);
}
