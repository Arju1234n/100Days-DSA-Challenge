# 12-BST

## Topic Introduction
A **Binary Search Tree (BST)** is a binary tree where for each node, all elements in its left subtree are strictly less than the node's value, and all elements in its right subtree are strictly greater than the node's value. This sorted ordering allows for fast lookup and insertion.

---

## When to use
- When order/sorting matters, and you need fast dynamic lookup/insert/deletes.
- Building ordered sets or maps.

---

## Time Complexities
| Operation | Average Case | Worst Case (Skewed) | Notes |
| :--- | :---: | :---: | :--- |
| **Search** | $O(\log n)$ | $O(n)$ | Worst case occurs if BST is not balanced |
| **Insertion** | $O(\log n)$ | $O(n)$ | Must find insertion spot |
| **Deletion** | $O(\log n)$ | $O(n)$ | Requires reorganizing node links |

---

## Common Patterns
1. **In-order Traversal**: Iterating BST in-order yields elements in **sorted ascending order**.
2. **BST Validation**: Ensuring elements lie within valid lower and upper bounds `(min_val, max_val)` for each subtree.
3. **Lowest Common Ancestor (LCA)**: Using the value comparisons to find node split points.

---

## Interview Tips
- The most common property utilized is: **Inorder traversal of BST gives a sorted array**.
- When validating a BST, do not just compare a node to its immediate children. Ensure all left subtree nodes are less than the current node, and all right subtree nodes are greater (use range limits `(low, high)` passed down).

---

## Mistakes to Avoid
- **Linear height assumptions**: Forgetting that un-balanced BSTs degrade to linked lists with $O(n)$ complexity.

---

## Solved Problems Checklist
- [ ] Validate Binary Search Tree | **Medium**
- [ ] Lowest Common Ancestor of a Binary Search Tree | **Easy**
- [ ] Delete Node in a BST | **Medium**
