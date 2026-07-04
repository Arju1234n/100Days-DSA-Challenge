# 20-Segment-Tree

## Topic Introduction
A **Segment Tree** is a tree data structure used for storing information about intervals, or segments. It allows querying which of the stored segments contains a given point, or performing range query computations (e.g. range sum, range minimum) in logarithmic time.

---

## When to use
- When asked to perform frequent **Range Queries** and **Point/Range Updates** dynamically on an array.
- For finding range sum, range minimum/maximum, or greatest common divisor of ranges dynamically.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Build Tree** | $O(n)$ | Construct tree from array |
| **Range Query** | $O(\log n)$ | Traverse path boundaries |
| **Point Update** | $O(\log n)$ | Modify value and propagate changes upward |

---

## Common Patterns
1. **Classic Segment Tree**: $O(4n)$ size array representing tree nodes.
2. **Lazy Propagation**: Postponing range updates to children to achieve $O(\log n)$ range updates (instead of $O(n)$).

---

## Interview Tips
- Segment trees require an array representation of size **$4n$**, where $n$ is the length of the input array. Make sure to size your storage vector/array accordingly.
- For simple range sum and point updates, a **Fenwick Tree (Binary Indexed Tree)** is often faster to write and consumes less space ($O(n)$ space).

---

## Mistakes to Avoid
- **Index calculations**: Be careful with left child ($2 \times i + 1$) and right child ($2 \times i + 2$) indices when building or traversing.

---## Solved Problems Checklist
- [ ] Range Sum Query - Mutable | **Medium**
- [ ] Range Minimum Query | **Medium**
