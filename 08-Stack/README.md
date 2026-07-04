# 08-Stack

## Topic Introduction
A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle. Stacks support two primary operations: `push` (insert an element to the top) and `pop` (remove an element from the top).

---

## When to use
- When order of execution needs to be reversed.
- During recursion or backtracking (Call Stack).
- When parsing nested structures like parenthesized expressions, XML tags, or math calculations.
- Tracking values dynamically (e.g. daily temperatures) using Monotonic Stacks.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Push** | $O(1)$ | Direct insertion at top |
| **Pop** | $O(1)$ | Direct removal from top |
| **Peek** | $O(1)$ | Retrieve top value without removal |
| **Search** | $O(n)$ | Must pop sequentially to find element |

---

## Common Patterns
1. **Valid Parentheses**: Matching corresponding pairs using stack push/pop.
2. **Monotonic Stack**: Storing elements in increasing or decreasing sorted order to find the next greater or smaller element in $O(n)$ time.
3. **Expression Evaluation**: Converting and resolving infix, postfix, or prefix notations.

---

## Interview Tips
- Always check if the stack is **empty** before running `pop()` or `peek()` to avoid empty-stack runtime exceptions.
- Stacks are often used to optimize algorithms by replacing recursion with iterative DFS.

---

## Mistakes to Avoid
- **Memory Overhead**: Stacking too many elements, which might lead to memory overflow.

---

## Solved Problems Checklist
- [ ] Valid Parentheses | **Easy**
- [ ] Evaluate Reverse Polish Notation | **Medium**
- [ ] Daily Temperatures | **Medium**
