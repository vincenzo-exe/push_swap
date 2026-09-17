/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahmamou <aahmamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:23:59 by aahmamou          #+#    #+#             */
/*   Updated: 2026/09/16 22:24:01 by aahmamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* Stack node */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Operations */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Parsing */
int		parse_arguments(int argc, char **argv, t_stack **stack_a);
int	is_valid_number(char *str);
int	parse_number(char *str, int *value);
int	has_duplicate(t_stack *stack, int value);

/* Stack creation / destruction */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);

/* Stack utilities */
int	stack_size(t_stack *stack);
int	stack_is_sorted(t_stack *stack);

/* Indexing */
void		assign_indexes(t_stack *stack);

/* Sorting */
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif
