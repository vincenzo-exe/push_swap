/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:19:14 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 13:19:16 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		prev = NULL;
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated;

	rotated = 0;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		reverse_rotate(stack_a);
		rotated = 1;
	}
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		reverse_rotate(stack_b);
		rotated = 1;
	}
	if (rotated)
		write(1, "rrr\n", 4);
}
