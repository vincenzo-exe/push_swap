/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:30:16 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/18 12:30:17 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initial_push(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (stack_size(*a) > 3)
		pb(a, b);
}

static void	push_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = turk_cheapest(*a, *b);
	turk_move_to_b(a, b, cheapest);
}

static void	push_all_to_b(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
		push_cheapest(a, b);
}

static void	final_rotate(t_stack **a)
{
	int	position;
	int	rotation;

	position = turk_min_position(*a);
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

void	turk_sort(t_stack **a, t_stack **b)
{
	initial_push(a, b);
	push_all_to_b(a, b);
	sort_three(a);
	turk_move_to_a(a, b);
	final_rotate(a);
}
