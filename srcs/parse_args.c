/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:30:12 by alibaba           #+#    #+#             */
/*   Updated: 2024/08/28 19:20:37 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	ft_add_to_stack(char *token, t_stack **stack_a, char **tokens)
{
	int	value;

	if (!token || *token == '\0' || !ft_is_valid_int(token)
		|| !ft_is_int_range(token))
	{
		ft_free_tokens(tokens);
		ft_free_stack(stack_a);
		ft_error();
	}
	value = ft_atoi(token);
	if (ft_has_duplicates(*stack_a, value))
	{
		ft_free_stack(stack_a);
		ft_free_tokens(tokens);
		ft_error();
	}
	ft_pushlst(stack_a, value);
}

static void	ft_handle_token(char *arg, t_stack **stack_a)
{
	char	**tokens;
	int		i;

	if (!arg || !*arg || ft_str_is_whitespace(arg))
	{
		ft_free_stack(stack_a);
		ft_error();
	}
	tokens = ft_split(arg, ' ');
	if (tokens)
	{
		i = -1;
		while (tokens[++i])
			ft_add_to_stack(tokens[i], stack_a, tokens);
		ft_free_tokens(tokens);
	}
}

void	ft_parse_args(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_handle_token(argv[i], stack_a);
	ft_assign_indexes(stack_a);
}
