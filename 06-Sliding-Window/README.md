# 06-Sliding-Window

## Topic Introduction
The **Sliding Window** algorithm is used to perform required operations on a specific window size of a given array or string. It helps avoid redundant calculations by expanding and shrinking a subarray/substring.

---

## When to use
- Finding the longest/shortest subarray or substring that satisfies a condition.
- Looking for optimal values in dynamic or fixed range elements.

---

## Time Complexities
| Pattern | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **Fixed Window** | $O(n)$ | $O(1)$ | Window size remains constant |
| **Dynamic Window** | $O(n)$ | $O(k)$ | Window size expands/shrinks dynamically |

---

## Common Patterns
1. **Fixed Size Window**: Maintain sum/metrics of $k$ consecutive elements.
2. **Variable Size Window**: Expand window using `right` pointer, shrink using `left` pointer until condition is met.

---

## Interview Tips
- Clarify if negative numbers are allowed in subarray sum problems, as they might invalidate standard greedy expansion logic.
- Initialize window variables carefully.

---

## Mistakes to Avoid
- Shrinking the window too much or forgetting to update indices.

---

## Solved Problems Checklist
- [ ] Longest Substring Without Repeating Characters | **Medium**
- [ ] Minimum Window Substring | **Hard**
