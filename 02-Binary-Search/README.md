# 02-Binary-Search

## Topic Introduction
**Binary Search** is a search algorithm that finds the position of a target value within a sorted array. It compares the target value to the middle element of the array; if they are not equal, the half in which the target cannot lie is eliminated, and the search continues on the remaining half.

---

## When to use
- When searching inside a **sorted array**.
- When asked to find a value with $O(\log n)$ time complexity.
- When searching for a threshold value where a boolean condition changes from `false` to `true` (Binary Search on Answer).

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Search Space Division** | $O(\log n)$ | Divides the search space by half in each iteration |
| **Space Complexity** | $O(1)$ | Iterative implementation uses constant memory |

---

## Common Patterns
1. **Classic Binary Search**: Finding an exact match of target.
2. **Left/Right Bound**: Finding the first or last occurrence of a target (lower/upper bounds).
3. **Rotated Sorted Arrays**: Finding pivot index and searching.
4. **Binary Search on Answer**: Minimizing or maximizing a target criteria (e.g., Koko eating bananas, capacity of ship).

---

## Interview Tips
- Clarify if the array has duplicate values, as this might break standard bounds assumptions.
- Beware of integer overflow when computing middle index: use `low + (high - low) / 2` instead of `(low + high) / 2`.
- Carefully choose the loop condition (`low <= high` vs `low < high`) based on whether you are looking for an exact element or a boundary index.

---

## Mistakes to Avoid
- **Infinite Loops**: Forgetting to update `low = mid + 1` or `high = mid - 1`, leading to loops that never terminate.
- **Incorrect Boundaries**: Returning wrong index when bounds overlap.

---

## Solved Problems Checklist
- [ ] Classic Binary Search | **Easy**
- [x] [Lower Bound](./lower_bound.cpp) | **Easy**
- [x] [First Occurrence in Sorted](./first_occurrence.cpp) | **Easy**
- [x] [Find First and Last Position of Element in Sorted Array](./find_first_and_last_position.cpp) | **Medium**
- [x] [Search Insert Position](./search_insert_position.cpp) | **Easy**
- [x] [Number of Occurrence](./number_of_occurrences.cpp) | **Easy**
- [ ] Search in Rotated Sorted Array | **Medium**
