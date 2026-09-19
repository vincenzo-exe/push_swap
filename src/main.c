/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:27:00 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 20:27:02 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_arguments(ac, av, &stack_a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	assign_indexes(stack_a);
	sort_stack(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
