# 11-Trees

## Topic Introduction
A **Tree** is a non-linear hierarchical data structure that consists of nodes connected by edges. The most common variant is the Binary Tree, where each node has at most two children: left and right.

---

## When to use
- Representing hierarchical structures (e.g. file systems, HTML DOM).
- Fast lookup, insertion, and deletion algorithms (when structured as BST).
- Syntax parsing trees.

---

## Time Complexities
| Traversal / Operation | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **Traversal (DFS/BFS)** | $O(n)$ | $O(h)$ | $h$ is tree height (recursion stack/queue size) |
| **Balanced Height** | $O(\log n)$ | - | Perfect tree height |

---

## Common Patterns
1. **Depth-First Search (DFS)**: Pre-order, In-order, Post-order traversals (recursive or using manual stack).
2. **Breadth-First Search (BFS)**: Level-order traversal using a queue.
3. **Subtree Validation**: Checking children height/balance conditions (e.g. Balanced Tree, Symmetric Tree).

---

## Interview Tips
- Base cases are crucial in tree recursion: always define actions for `node == null` first.
- BFS is ideal for shortest-path questions on trees (e.g. min depth).
- Learn both iterative and recursive implementations for tree traversals.

---

## Mistakes to Avoid
- **Stack Overflow**: Extremely unbalanced trees can have height $O(n)$, causing recursion stack overflow.
- **Null Reference**: Accessing `node->left->val` without checking if `node->left` is null.

---

## Solved Problems Checklist
- [ ] Invert Binary Tree | **Easy**
- [ ] Maximum Depth of Binary Tree | **Easy**
- [ ] Binary Tree Level Order Traversal | **Medium**
