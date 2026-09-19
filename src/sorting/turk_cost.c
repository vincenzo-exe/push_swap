/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:30:09 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/18 12:30:10 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	turk_rotation(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (position - size);
}

int	turk_cost(t_stack *a, t_stack *b, t_stack *node)
{
	int	a_rot;
	int	b_rot;
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	b_size = stack_size(b);
	a_rot = turk_rotation(turk_position(a, node->index), a_size);
	b_rot = turk_rotation(turk_target_b(b, node->index), b_size);
	if ((a_rot >= 0 && b_rot >= 0)
		|| (a_rot < 0 && b_rot < 0))
	{
		if (a_rot < 0)
			a_rot = -a_rot;
		if (b_rot < 0)
			b_rot = -b_rot;
		if (a_rot > b_rot)
			return (a_rot + 1);
		return (b_rot + 1);
	}
	if (a_rot < 0)
		a_rot = -a_rot;
	if (b_rot < 0)
		b_rot = -b_rot;
	return (a_rot + b_rot + 1);
}

t_stack	*turk_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*start;
	t_stack	*cheapest;
	int		cheapest_cost;
	int		current_cost;

	start = a;
	cheapest = a;
	cheapest_cost = turk_cost(start, b, a);
	a = a->next;
	while (a)
	{
		current_cost = turk_cost(start, b, a);
		if (current_cost < cheapest_cost)
		{
			cheapest = a;
			cheapest_cost = current_cost;
		}
		a = a->next;
	}
	return (cheapest);
}
