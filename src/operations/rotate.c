/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:19:26 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 13:19:27 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void	ra(t_stack **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated;

	rotated = 0;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		rotate(stack_a);
		rotated = 1;
	}
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		rotate(stack_b);
		rotated = 1;
	}
	if (rotated)
		write(1, "rr\n", 3);
}
