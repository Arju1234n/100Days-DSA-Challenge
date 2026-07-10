# 05-Two-Pointers

## Topic Introduction
The **Two Pointers** technique is an algorithmic pattern where two pointers are maintained to traverse data structures (usually arrays or linked lists) simultaneously. This is often used to optimize nested loop solutions ($O(n^2)$) to $O(n)$ time complexity.

---

## When to use
- Finding a pair of elements that satisfy a condition in a **sorted array** (e.g. Target Sum).
- Reversing elements or partitioning arrays (e.g. QuickSelect, QuickSort partition).
- Detecting cycles in linked lists (Fast/Slow pointers).

---

## Time Complexities
| Pattern | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **Converging Pointers** | $O(n)$ | $O(1)$ | Left & Right pointers moving inward |
| **Fast & Slow Pointers** | $O(n)$ | $O(1)$ | One pointer moves twice as fast |

---

## Common Patterns
1. **Left-Right Converging**: Pointers start at opposite ends and move toward each other (e.g. 2-Sum Sorted, Palindromes, Container Water).
2. **Fast-Slow Pointers**: Also called tortoise & hare (e.g. Cycle Detection, Middle of Linked List).
3. **Partition Pointer**: Used in QuickSort / array partitioning.

---

## Interview Tips
- Make sure the array is **sorted** before using the Left-Right converging pattern. If not, consider sorting it first.
- Clearly define the movement conditions: under what condition does `left` increment, and under what condition does `right` decrement?

---

## Mistakes to Avoid
- **Pointer Crossing**: Forgetting the `left < right` bounds check inside inner helper loops, causing memory page faults or out of index access.
- **Infinite Loop**: Forgetting to update pointers in some logical branches.

---

## Solved Problems Checklist
- [x] [Valid Palindrome](./valid_palindrome.cpp) | **Easy**
- [x] [Container With Most Water](./container_with_most_water.cpp) | **Medium**
- [x] [3Sum](./three_sum.cpp) | **Medium**
- [x] [Two Sum II - Input Array Is Sorted](./two_sum_sorted.cpp) | **Medium**
- [x] [4Sum](./four_sum.cpp) | **Medium**
- [x] [Find Pair with Given Difference](./pair_with_difference.cpp) | **Easy**
