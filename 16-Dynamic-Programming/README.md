# 16-Dynamic-Programming

## Topic Introduction
**Dynamic Programming (DP)** is an algorithmic paradigm that solves a complex problem by breaking it into subproblems, solving each subproblem once, and storing their solutions (using memoization or tabulation) to avoid redundant computations.

---

## When to use
- Overlapping Subproblems: Recursion solves the same subproblem repeatedly.
- Optimal Substructure: Optimal solution of the problem can be constructed from optimal solutions of its subproblems.
- Often phrased as "Find the maximum/minimum value...", "How many ways to...", etc.

---

## Time Complexities
| Method | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **Memoization (Top-down)** | $O(N)$ | $O(N)$ | Recursion stack overhead |
| **Tabulation (Bottom-up)** | $O(N)$ | $O(N)$ | Iterative matrix/array filling |
| **Space Optimized** | $O(N)$ | $O(1)$ | Storing only last few states |

---

## Common Patterns
1. **0/1 Knapsack**: Choose or ignore elements with constraints.
2. **Unbounded Knapsack**: Multiple choices allowed.
3. **Fibonacci / Decision Sequence**: e.g., Climb Stairs, House Robber.
4. **Longest Common Subsequence (LCS)**: String alignments.
5. **Longest Increasing Subsequence (LIS)**: Partition and match indices.

---

## Interview Tips
- Start by defining the **DP state** (what does `dp[i]` or `dp[i][j]` represent?).
- Formulate the **State Transition Relation** (e.g. `dp[i] = dp[i-1] + dp[i-2]`).
- Think about the **base cases** (e.g., `dp[0] = 0`, `dp[1] = 1`).
- Optimize space complexity if you only need the results of the previous 1 or 2 iterations.

---

## Mistakes to Avoid
- **Inefficient Recursion**: Not adding a memoization cache, resulting in $O(2^n)$ runtime instead of $O(n)$.
- **Wrong matrix sizing**: Forgetting offset/index mappings for 1-based indexing.

---

## Solved Problems Checklist
- [ ] Climbing Stairs | **Easy**
- [ ] Longest Increasing Subsequence | **Medium**
- [ ] Edit Distance | **Hard**
