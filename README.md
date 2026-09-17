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

For this implementation, the numbers are first converted to indexes based on their relative order. This makes it possible to use a binary Radix sort while keeping the original values unchanged.

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

### Current performance

Using the current Radix implementation, one tested run produced:

| Input              | Operations |
| ------------------ | ---------: |
| 100 random numbers |       1084 |
| 500 random numbers |       6784 |

These results satisfy the 42 minimum validation range of under 1100 operations for 100 numbers and under 8500 operations for 500 numbers.

Performance can be improved further with a more operation-efficient sorting strategy.

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
    │   ├── radix.c
    │   ├── small_sort.c
    │   └── sort.c
    └── utils/
        ├── free.c
        └── stack_utils.c
```

## Technical Choices

### Linked-list stacks

Both stacks are represented using linked lists. Each node stores:

* The original integer value
* Its sorted index
* A pointer to the next node

### Coordinate compression

The original values can be very large or negative, so they are converted to indexes based on their relative order.

For example:

```text
-100  → 0
-7    → 1
0     → 2
42    → 3
50    → 4
```

The Radix algorithm then works with these indexes instead of the original values.

### Radix sort

The implementation uses binary LSD Radix sort.

For each bit:

* `0` → push the element from A to B
* `1` → rotate A
* At the end of the pass, elements are pushed back from B to A

This process is repeated for all required bits.

### Small sorting

Inputs containing two or three elements are handled separately to avoid unnecessary Radix passes.

## Resources

The project was developed using the 42 Push_swap subject together with documentation and external resources about stacks, sorting algorithms, Radix sort, Push_swap strategies, testing, and visualization.

Useful resources include:

* 42 Push_swap subject
* Push_swap visualizers
* Sorting algorithm documentation
* Push_swap algorithm articles on Medium

Some useful references are listed below:

* `o-reo/push_swap_visualizer` — Push_swap visualizer
* `Hqndler/42-push_swap` — Push_swap implementation and performance discussion
* `42YerevanProjects/push_swap` — Radix-based Push_swap implementation
* `Push_Swap: The least amount of moves with two stacks` — Medium article about Push_swap optimization
* `Push swap tutorial` — Medium article explaining a Radix-based approach

## AI Usage

AI was used as a learning and development assistant during this project.

It was used for:

* Understanding the Push_swap subject and requirements
* Discussing parsing and input validation
* Understanding coordinate compression and Radix sort
* Debugging compilation and linker errors
* Reviewing operation behavior and edge cases
* Designing and improving tests
* Investigating Push_swap optimization strategies
