#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_arguments(argc, argv, &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	assign_indexes(stack_a);
	sort_stack(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}