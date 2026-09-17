#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}