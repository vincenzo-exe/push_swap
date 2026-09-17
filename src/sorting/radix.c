#include "push_swap.h"

static void	radix_pass(t_stack **stack_a, t_stack **stack_b,
		int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*stack_a)->index >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;
	int	bits;
	int	bit;

	size = stack_size(*stack_a);
	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	bit = 0;
	while (bit < bits)
	{
		radix_pass(stack_a, stack_b, bit, size);
		bit++;
	}
}