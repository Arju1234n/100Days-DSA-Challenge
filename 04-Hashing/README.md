# 04-Hashing

## Topic Introduction
**Hashing** is a process that maps keys/values into database entries using hash functions. Hash tables or hash maps are essential data structures that provide average-case $O(1)$ operations for insertion, search, and deletion.

---

## When to use
- When lookup/search efficiency is the primary bottleneck.
- For tracking frequency counts, duplicate items, or elements visited so far.
- When computing associations (e.g. key-value pairs).

---

## Time Complexities
| Operation | Average Case | Worst Case | Notes |
| :--- | :---: | :---: | :--- |
| **Search** | $O(1)$ | $O(n)$ | Worst case occurs under severe hash collisions |
| **Insertion** | $O(1)$ | $O(n)$ | Worst case requires resizing and rehashing |
| **Deletion** | $O(1)$ | $O(n)$ | Direct entry removal |

---

## Common Patterns
1. **Frequency Counter**: Storing mapping counts.
2. **Visited Set**: Tracking set membership to avoid processing same items.
3. **Index Map**: Storing `value -> index` mapping (e.g. Two Sum).

---

## Interview Tips
- Clarify if keys are integers or complex objects. Complex objects require custom hash functions in C++.
- Be mindful of collision resolution details (chaining vs open addressing) for theoretical questions.
- A hash table does not preserve **order**. If sorting or order matters, consider standard ordered maps (which use Balanced BSTs, like `std::map` in C++, with $O(\log n)$ search).

---

## Mistakes to Avoid
- **Unnecessary keys creation**: Creating dictionary items dynamically when checking existence.
- **High collision rate**: Using poor quality custom hash functions.

---

## Solved Problems Checklist
- [ ] Group Anagrams | **Medium**
- [ ] Top K Frequent Elements | **Medium**
- [ ] Longest Consecutive Sequence | **Medium**
