/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:29:25 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/17 13:28:35 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (*from != NULL)
	{
		temp = *from;
		*from = (*from)->next;
		temp->next = *to;
		*to = temp;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b != NULL)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}
