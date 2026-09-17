/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:27:36 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 20:27:37 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **tokens)
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

static int	add_number(t_stack **stack, char *str)
{
	int		value;
	t_stack	*new_node;

	if (!is_valid_number(str))
		return (0);
	if (!parse_number(str, &value))
		return (0);
	if (has_duplicate(*stack, value))
		return (0);
	new_node = stack_new(value);
	if (!new_node)
		return (0);
	stack_add_back(stack, new_node);
	return (1);
}

static int	process_argument(char *arg, t_stack **stack)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	i = 0;
	while (tokens[i])
	{
		if (!add_number(stack, tokens[i]))
		{
			free_tokens(tokens);
			return (0);
		}
		i++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_argument(argv[i], stack_a))
		{
			stack_clear(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}
