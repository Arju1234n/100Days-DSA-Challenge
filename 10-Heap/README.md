# 10-Heap

## Topic Introduction
A **Heap** is a specialized tree-based data structure that satisfies the heap property: in a max heap, for any given node $C$, if $P$ is a parent node of $C$, then the key of $P$ is greater than or equal to the key of $C$. Min heaps store the smallest element at the root. Heaps are typically implemented using arrays.

---

## When to use
- When you need constant-time access $O(1)$ to the maximum or minimum element.
- When retrieving the top $K$ largest or smallest elements dynamically from a stream.
- Priority Queue scheduling tasks.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Get Max/Min** | $O(1)$ | Accessing root element |
| **Insert** | $O(\log n)$ | Requires heapifying up |
| **Delete Max/Min** | $O(\log n)$ | Requires heapifying down |
| **Heapify Array** | $O(n)$ | Linear time heap construction |

---

## Common Patterns
1. **Top K Elements**: Maintaining a min-heap of size $K$ to get the largest elements.
2. **K-Way Merge**: Merging $K$ sorted streams using priority queue.
3. **Two Heaps**: Tracking median of streaming numbers (Min-heap for upper half, Max-heap for lower half).

---

## Interview Tips
- In Python, `heapq` implements a **Min Heap** by default. To use a Max Heap, negate your values before inserting.
- In C++, `std::priority_queue` is a **Max Heap** by default. Use `std::priority_queue<int, std::vector<int>, std::greater<int>>` for a Min Heap.
- Building a heap from an unsorted array takes $O(n)$ time using `heapify`, which is faster than inserting elements one by one ($O(n \log n)$).

---

## Mistakes to Avoid
- **Keeping size unbound**: Letting the heap size grow to $N$ when solving a Top-K problem (which requires $O(n \log n)$ instead of $O(n \log k)$). Always pop excess elements to keep heap size at $K$.

---

## Solved Problems Checklist
- [ ] Kth Largest Element in an Array | **Medium**
- [ ] Merge k Sorted Lists | **Hard**
- [ ] Find Median from Data Stream | **Hard**
