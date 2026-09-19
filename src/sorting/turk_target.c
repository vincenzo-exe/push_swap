/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:29:59 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/18 12:30:00 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	turk_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	turk_max_position(t_stack *stack)
{
	int	max;
	int	position;
	int	i;

	max = stack->index;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int	turk_min_position(t_stack *stack)
{
	int	min;
	int	position;
	int	i;

	min = stack->index;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

static int	find_predecessor(t_stack *stack, int index)
{
	int	best;
	int	position;
	int	i;

	best = -1;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < index
			&& (best == -1 || stack->index > best))
		{
			best = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int	turk_target_b(t_stack *stack, int index)
{
	t_stack	*start;
	int		max;
	int		min;

	start = stack;
	max = stack->index;
	min = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	if (index > max || index < min)
		return (turk_max_position(start));
	return (find_predecessor(start, index));
}
