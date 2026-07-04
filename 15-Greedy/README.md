# 15-Greedy

## Topic Introduction
A **Greedy Algorithm** builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit (locally optimal choice) to find the globally optimal solution.

---

## When to use
- Problems where local optimizations guarantee a global optimal solution (e.g. fractional knapsack, interval scheduling).
- In optimization problems where computing all options is too slow ($O(2^n)$) but sorting/heaps reveal a straightforward optimal order.

---

## Time Complexities
| Method / Strategy | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Greedy with Sorting** | $O(n \log n)$ | Sort elements first, then process |
| **Greedy with Heap** | $O(n \log k)$ | Maintain top elements priority |

---

## Common Patterns
1. **Interval Scheduling**: Sorting intervals by start or end times (e.g. Merge Intervals, Non-overlapping Intervals).
2. **Two Pointers/Greedy**: Making decisions based on local metrics (e.g. Jump Game, Container Water).

---

## Interview Tips
- Greedy algorithms are simple to write but hard to prove mathematically. Always verify your logic with small edge cases or counter-examples.
- If sorting elements is a prerequisite, sorting by **start time** vs. **end time** can produce completely different results. Test both configurations.

---

## Mistakes to Avoid
- **False assumption**: Assuming greedy works when the problem actually requires Dynamic Programming (e.g. 0-1 Knapsack, Coin Change).

---

## Solved Problems Checklist
- [ ] Jump Game | **Medium**
- [ ] Gas Station | **Medium**
- [ ] Hand of Straights | **Medium**
