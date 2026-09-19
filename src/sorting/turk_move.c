/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:29:42 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/18 12:29:44 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, int *a_rot, int *b_rot)
{
	while (*a_rot > 0 && *b_rot > 0)
	{
		rr(a, b);
		(*a_rot)--;
		(*b_rot)--;
	}
	while (*a_rot < 0 && *b_rot < 0)
	{
		rrr(a, b);
		(*a_rot)++;
		(*b_rot)++;
	}
}

static void	rotate_a(t_stack **a, int *rot)
{
	while (*rot > 0)
	{
		ra(a);
		(*rot)--;
	}
	while (*rot < 0)
	{
		rra(a);
		(*rot)++;
	}
}

static void	rotate_b(t_stack **b, int *rot)
{
	while (*rot > 0)
	{
		rb(b);
		(*rot)--;
	}
	while (*rot < 0)
	{
		rrb(b);
		(*rot)++;
	}
}

void	turk_move_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	int	a_rot;
	int	b_rot;

	a_rot = turk_rotation(turk_position(*a, node->index),
			stack_size(*a));
	b_rot = turk_rotation(turk_target_b(*b, node->index),
			stack_size(*b));
	rotate_both(a, b, &a_rot, &b_rot);
	rotate_a(a, &a_rot);
	rotate_b(b, &b_rot);
	pb(a, b);
}
