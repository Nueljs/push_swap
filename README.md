*This project has been created as part of the 42 curriculum by macerver.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using the **minimum number of operations**, with only two stacks (A and B) and a limited set of allowed instructions.

The program receives a list of integers as arguments and prints to stdout the optimal (or near-optimal) sequence of instructions that sorts stack A in ascending order.

### Allowed instructions

| Instruction | Description |
|-------------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

### Performance targets

| Input size | Maximum moves |
|------------|---------------|
| 3 numbers  | ≤ 3           |
| 5 numbers  | ≤ 12          |
| 100 numbers | ≤ 700        |
| 500 numbers | ≤ 5500       |

---

## Algorithm — The Turk Algorithm

This implementation is based on a **greedy cost-based insertion strategy** commonly known as the **Turk algorithm**, which operates in three phases:

### Phase 1 — Move elements to stack B

All elements except 3 are pushed from A to B. Before each push, the algorithm calculates the **cost** of moving every element of A into its correct position in B, and always moves the **cheapest** one first.

The cost of moving element `x` from A to B is the total number of instructions needed to:
1. Bring `x` to the top of A (via `ra` or `rra`)
2. Bring `x`'s target position to the top of B (via `rb` or `rrb`)
3. Execute the `pb`

The key optimization is that when A and B need to rotate in the **same direction**, the algorithm uses the simultaneous `rr` or `rrr` instructions, which count as a single move. This can drastically reduce costs.

The target for `x` in B is the **largest element smaller than `x`**. If no such element exists (i.e., `x` is smaller than everything in B), the target is the **maximum** of B (wrap-around insertion).

### Phase 2 — Sort the 3 remaining elements in A

With only 3 elements left in A, an optimal sort is applied using at most 2 instructions.

### Phase 3 — Push everything back from B to A

Elements are pushed back from B to A. Stack B is sorted in descending order at this point, and each element is inserted into its correct position in A by rotating A until the right slot is at the top, then executing `pa`.

For each element at the top of B, the algorithm finds the **smallest element in A greater than** the element being inserted as the target. If none exists, the target is the maximum of A (wrap-around).

### Final step

Once all elements are back in A, a final `ra`/`rra` sequence places the minimum element at the top, completing the sort.

---

## Project structure

```
push_swap/
├── push_swap.c          # Entry point, argument parsing
├── push_swap.h          # Header: structs and function declarations
├── Makefile
├── algorithm/
│   ├── algorithm.c      # Main algorithm orchestration
│   ├── cost.c           # Cost calculation for A→B insertions
│   ├── ejecute_moves.c  # Optimized move execution (rr/rrr)
│   ├── alg_utils.c      # Index calculation, push_to_b, reset_target
│   └── push_to_a.c      # B→A insertion logic
├── moves/
│   ├── push.c           # pa, pb
│   ├── swap.c           # sa, sb, ss
│   ├── rotate.c         # ra, rb, rr
│   └── rrotate.c        # rra, rrb, rrr
├── utils/
│   ├── utils.c          # ft_atoi, ft_atol, ft_isnumber, ft_strlen
│   ├── utils2.c         # ft_strchr, ft_strdup, ft_substr
│   ├── utils3.c         # sort_2, sort_3, check_doubles, free_stack
│   ├── lst_utils.c      # ft_lstnew, ft_lstadd_back, ft_lstadd_front, ft_lstsize
│   └── ft_split.c       # ft_split
└── ft_printf/           # Custom ft_printf implementation
```

---

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` binary. Available Makefile targets:

| Target | Description |
|--------|-------------|
| `make` / `make all` | Compile the binary |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | Full recompile |

### Execution

Arguments can be passed as separate values or as a quoted string:

```bash
./push_swap 4 2 7 1 5
./push_swap "4 2 7 1 5"
```

The program prints to stdout the sequence of instructions that sorts the input. If the input is invalid (non-integer, duplicate, or out of int range), it prints `Error` to stderr.

### Counting moves

```bash
./push_swap $(python3 -c "import random; nums=random.sample(range(-10000,10001),500); print(*nums)") | wc -l
```

---

## Resources

### Documentation and references

- [push_swap — Medium article by Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-number-of-moves-with-two-stacks-d1e76a71789a) — Detailed explanation of the Turk algorithm and cost-based approach.
- [push_swap — Medium article by A. Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — Detailed explanation of the Turk algorithm and cost-based approach.
- Wikipedia: [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) — Background on sorting complexity and strategies.

### AI usage

Claude (claude.ai) was used during this project for the following purposes:

- **Debugging**: Identifying logical errors in cost calculation and target assignment functions (`calc_target_b`, `cost`).
- **Algorithm analysis**: Understanding why the B→A phase produced suboptimal move counts for large inputs (500 numbers), and identifying that the lack of cost-based selection in that phase was the bottleneck.
- **Concept clarification**: Explaining why B being sorted in descending order does not make sequential insertion optimal, and why combined `rr`/`rrr` operations during B→A reinsertion can significantly reduce move count.

No code was generated directly by AI — it was used as a reasoning and debugging assistant.
