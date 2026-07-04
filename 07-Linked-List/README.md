# 07-Linked-List

## Topic Introduction
A **Linked List** is a linear data structure where elements are not stored at contiguous memory locations. Instead, elements are linked using pointers. Singly Linked Lists, Doubly Linked Lists, and Circular Linked Lists are primary variants.

---

## When to use
- When size is dynamic and frequent insertions/deletions at the ends are required ($O(1)$ time).
- When sequential traversal is sufficient (no random index access required).

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Search** | $O(n)$ | Must traverse linearly |
| **Insertion at Head** | $O(1)$ | Update head pointer |
| **Insertion at Tail** | $O(1)$ | If tail pointer is tracked, else $O(n)$ |
| **Deletion** | $O(1)$ | Once node reference is obtained |

---

## Common Patterns
1. **Reverse Linked List**: Reversing link directions iteratively or recursively.
2. **Two Pointers (Fast/Slow)**: Cycle detection, finding middle node, detecting intersections.
3. **Dummy Node**: Simplifying edge cases (like head deletion or merging lists).

---

## Interview Tips
- Always check if the current node or next node (`node->next`) is **null** to prevent segmentation faults.
- Drawing diagrams on paper or a whiteboard is extremely helpful when tracing pointer manipulations.
- Consider utilizing a **dummy head node** to make insertions and deletions at the head uniform with other positions.

---

## Mistakes to Avoid
- **Memory leaks**: In C++, forgetting to delete deleted nodes.
- **Pointer loss**: Re-assigning pointers before saving the target destination.

---

## Solved Problems Checklist
- [ ] Reverse Linked List | **Easy**
- [ ] Merge Two Sorted Lists | **Easy**
- [ ] Linked List Cycle | **Easy**
