#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("value = %d, index = %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (!parse_arguments(argc, argv, &stack_a))
	{
		printf("Error\n");
		return (1);
	}
	print_stack(stack_a);
	stack_clear(&stack_a);
	return (0);
}