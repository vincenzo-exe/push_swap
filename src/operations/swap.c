/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:19:39 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 13:19:40 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void	sa(t_stack *stack_a)
{
	if (stack_a != NULL && stack_a->next != NULL)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack_b)
{
	if (stack_b != NULL && stack_b->next != NULL)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	swapped;

	swapped = 0;
	if (stack_a != NULL && stack_a->next != NULL)
	{
		swap(stack_a);
		swapped = 1;
	}
	if (stack_b != NULL && stack_b->next != NULL)
	{
		swap(stack_b);
		swapped = 1;
	}
	if (swapped)
		write(1, "ss\n", 3);
}
