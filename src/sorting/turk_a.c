/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:30:26 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/18 12:30:27 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_successor(t_stack *a, int index)
{
	int	best;
	int	position;
	int	i;

	best = -1;
	position = 0;
	i = 0;
	while (a)
	{
		if (a->index > index
			&& (best == -1 || a->index < best))
		{
			best = a->index;
			position = i;
		}
		a = a->next;
		i++;
	}
	return (position);
}

int	turk_target_a(t_stack *a, int index)
{
	t_stack	*start;
	int		min;
	int		max;

	start = a;
	min = a->index;
	max = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	if (index < min || index > max)
		return (turk_min_position(start));
	return (find_successor(start, index));
}

static void	rotate_a_to_target(t_stack **a, int index)
{
	int	position;
	int	rotation;

	position = turk_target_a(*a, index);
	rotation = turk_rotation(position, stack_size(*a));
	while (rotation > 0)
	{
		ra(a);
		rotation--;
	}
	while (rotation < 0)
	{
		rra(a);
		rotation++;
	}
}

void	turk_move_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		rotate_a_to_target(a, (*b)->index);
		pa(a, b);
	}
}
