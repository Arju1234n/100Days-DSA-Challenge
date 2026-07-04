# 09-Queue

## Topic Introduction
A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle. The element added first is the one removed first. Double-ended queues (Deques) allow insertions and deletions from both ends.

---

## When to use
- When order of arrival must be preserved (e.g. print jobs, CPU tasks scheduling).
- In Graph traversals like Breadth-First Search (BFS) to track nodes to visit.
- For buffer management (like streaming audio/video).

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Enqueue** | $O(1)$ | Insert element at back |
| **Dequeue** | $O(1)$ | Remove element from front |
| **Peek** | $O(1)$ | Check front element |

---

## Common Patterns
1. **Breadth-First Search (BFS)**: Tracking node boundaries queue level-by-level.
2. **Monotonic Queue**: Finding max/min values in sliding windows (using deque to pop elements from both ends).
3. **Queue using Stacks**: Emulating queue behaviour with two stacks.

---

## Interview Tips
- Deque (`std::deque` in C++, `collections.deque` in Python) is preferred over vector/list because it provides $O(1)$ insertions and deletions at both front and back.
- Double check boundaries when resizing a circular queue implementation.

---

## Mistakes to Avoid
- **Linear queue resizing**: In C++, using `std::vector` for queues results in $O(n)$ front removals. Always use deque.

---

## Solved Problems Checklist
- [ ] Implement Queue using Stacks | **Easy**
- [ ] Sliding Window Maximum | **Hard**
