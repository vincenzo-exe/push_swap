/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:28:23 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 20:28:25 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_stack *stack, int value)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		if (stack->value < value)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		current->index = count_smaller(stack, current->value);
		current = current->next;
	}
}
