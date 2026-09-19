*This project has been created as part of the 42 curriculum by aahmamou.*

# Push_swap

## Description

Push_swap is a 42 project about sorting numbers using two stacks and a limited set of operations.

The program receives a list of integers as arguments and outputs a sequence of operations that sorts the numbers in ascending order in stack A.

The project focuses on:

* Parsing and validating input
* Working with linked lists and stacks
* Understanding sorting algorithms
* Managing memory in C
* Reducing the number of operations used to sort the stack

For this implementation, the numbers are first converted to indexes based on their relative order. This allows the sorting algorithm to work with simple ranks while keeping the original values unchanged.

The main sorting strategy used in this branch is the **Turk algorithm**, a cost-based Push_swap strategy that selects elements according to the number of operations required to move them between the two stacks.

Small inputs are handled separately with dedicated sorting functions.

## Instructions

### Compilation

From the project root:

```bash
make
```

This creates the `push_swap` executable.

To remove object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

### Usage

Run the program with numbers as arguments:

```bash
./push_swap 2 1 3
```

The program outputs the operations needed to sort the stack.

Numbers can also be provided as a quoted string:

```bash
./push_swap "4 2 1 3"
```

Mixed arguments are supported:

```bash
./push_swap 4 "2 1" 3
```

If the input is invalid, contains duplicates, or contains a number outside the `int` range, the program prints:

```text
Error
```

Already sorted input produces no output.

### Checking operation count

For example:

```bash
ARG=$(shuf -i 1-100000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

For 500 numbers:

```bash
ARG=$(shuf -i 1-100000 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

## Project Structure

```text
push_swap/
├── Makefile
├── README.md
├── push_swap.h
├── libft/
└── src/
    ├── main.c
    ├── operations/
    │   ├── push.c
    │   ├── reverse_rotate.c
    │   ├── rotate.c
    │   └── swap.c
    ├── parsing/
    │   ├── parse.c
    │   ├── stack_init.c
    │   └── validation.c
    ├── sorting/
    │   ├── indexing.c
    │   ├── small_sort.c
    │   ├── sort.c
    │   ├── turk_a.c
    │   ├── turk_cost.c
    │   ├── turk_move.c
    │   ├── turk_sort.c
    │   └── turk_target.c
    └── utils/
        ├── free.c
        └── stack_utils.c
```

## Technical Choices

### Linked-list stacks

Both stacks are represented using linked lists.

Each node stores:

* The original integer value
* Its sorted index
* A pointer to the next node

```c
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;
```

### Coordinate compression

The original values are converted to indexes based on their relative order.

For example:

```text
-100  → 0
-7    → 1
0     → 2
42    → 3
50    → 4
```

The original values remain stored in the nodes, while the sorting algorithm uses the indexes to determine their relative order.

### Small sorting

Inputs containing two or three elements are handled separately.

For two elements, the program swaps them only when they are in the wrong order.

For three elements, the program uses a small set of `sa`, `ra`, and `rra` operations to handle all possible permutations.

This avoids using the more general Turk algorithm when the input is already small.

### Turk sorting

For larger inputs, this branch uses a cost-based Turk sorting strategy.

The algorithm works in several stages:

1. Two elements are initially pushed from A to B when necessary, leaving three elements in A.
2. The remaining elements in A are evaluated according to the cost of moving them to B.
3. For each candidate, the algorithm calculates the required rotations in A and the target position in B.
4. When both stacks need to rotate in the same direction, `rr` or `rrr` can combine the rotations.
5. The cheapest candidate is moved from A to B.
6. Once three elements remain in A, those three elements are sorted.
7. Elements are then moved from B back to A using their correct target positions.
8. Finally, A is rotated so that the smallest index is at the top.

The cost calculation considers both stack rotations and the final push operation.

### Rotation optimization

The algorithm represents rotations using signed values:

```text
positive → ra / rb
negative → rra / rrb
```

When both stacks rotate in the same direction, combined operations can be used:

```text
ra  + rb  → rr
rra + rrb → rrr
```

This reduces the number of operations required to move an element.

## Resources

The project was developed using the 42 Push_swap subject together with documentation and external resources about stacks, sorting algorithms, Push_swap strategies, testing, and visualization.

Useful resources include:

* 42 Push_swap subject
* Push_swap visualizers
* Sorting algorithm documentation
* Push_swap algorithm articles

## AI Usage

AI was used as a learning and development assistant during this project.

It was used for:

* Understanding the Push_swap subject and requirements
* Debugging compilation and linker errors
* Reviewing operation behavior and edge cases
* Understanding the Turk sorting strategy
* Designing and improving tests
* Investigating Push_swap operation optimization
