#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(*stack_a);
}

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		ra(stack_a);
	else if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(*stack_a);
}