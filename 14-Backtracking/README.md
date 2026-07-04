# 14-Backtracking

## Topic Introduction
**Backtracking** is an algorithmic technique that solves problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time. It is effectively a systematic search of a state space tree.

---

## When to use
- When asked to find all combinations, permutations, subsets, or paths that meet a criteria.
- Solving state-space puzzles (e.g. Sudoku, N-Queens, Maze navigation).

---

## Time Complexities
| Problem Type | Common Time Complexity | Notes |
| :--- | :---: | :--- |
| **Permutations** | $O(n!)$ | Factorial search space |
| **Subsets** | $O(2^n)$ | Exponential search space |
| **Combinations** | $O(\binom{n}{k})$ | N choose K combinations |

---

## Common Patterns
1. **Decision State Space Template**:
   ```python
   def backtrack(state, path, result):
       if is_goal(state):
           result.append(list(path))
           return
       for choice in get_choices(state):
           if is_valid(choice):
               path.append(choice) # make choice
               backtrack(next_state(state, choice), path, result)
               path.pop()          # undo choice
   ```

---

## Interview Tips
- Identify the **three pillars of backtracking**: Decisions, Constraints, and Goals.
- Draw the recursion decision tree to visualize how branches are pruned.
- Passing temporary path variables by reference and using backtracking (push/pop) is much faster than passing copies by value in recursive parameters.

---

## Mistakes to Avoid
- **Forgetting to backtracking**: Forgetting to remove the last choice (undoing state modifications) after returning from recursion.
- **Copy overhead**: Duplicating arrays on every call instead of updating in-place.

---

## Solved Problems Checklist
- [ ] Subsets | **Medium**
- [ ] Permutations | **Medium**
- [ ] N-Queens | **Hard**
