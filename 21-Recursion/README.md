# 21-Recursion

## Topic Introduction
**Recursion** is a programming technique where a function calls itself, directly or indirectly, to solve a problem by breaking it down into smaller subproblems of the same nature. It relies on a base case to terminate execution and prevent infinite recursion.

---

## When to use
- Problems that can be naturally divided into similar subproblems (e.g., Tree traversals, Divide and Conquer).
- Generating combinations, permutations, or subsets.
- Graph traversals like DFS.

---

## Time Complexities
| Pattern | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **Linear Recursion** | $O(n)$ | $O(n)$ | Call stack depth scales linearly with input |
| **Divide and Conquer** | $O(n \log n)$ | $O(\log n)$ | Splitting problem in halves (e.g. Merge Sort) |
| **Exponential Recursion** | $O(2^n)$ | $O(n)$ | Branching factor of 2 (e.g. Fibonacci, subsets) |

---

## Common Patterns
1. **Base Case & Recursive Case**: Always establish the stopping condition first.
2. **Top-Down (Accumulator) vs Bottom-Up (Return Values)**: Deciding whether to pass results down through arguments or bubble them up through return statements.
3. **Decrease and Conquer / Divide and Conquer**: Reducing problem size or splitting into multiple independent subproblems.

---

## Interview Tips
- Identify the base case(s) first.
- Draw out the recursion tree to visualize recursive calls, which makes it easier to compute time and space complexity (stack space).
- Be mindful of recursion depth limits.

---

## Mistakes to Avoid
- **Stack Overflow**: Forgetting or incorrectly implementing the base case.
- **Redundant Work**: Recomputing subproblems (can be optimized using Memoization/DP).

---

## Solved Problems Checklist
- [ ] Subsets | **Medium**
- [ ] Combinations | **Medium**
- [ ] Permutations | **Medium**
- [x] [Fibonacci Number](./fibonacci_number.cpp) | **Easy**
- [x] [Sum of First N Natural Numbers](./sum_of_n.cpp) | **Easy**
- [x] [Factorial of N](./factorial_of_n.cpp) | **Easy**
- [x] [Print Numbers from 1 to N](./print_n_numbers.cpp) | **Medium**
