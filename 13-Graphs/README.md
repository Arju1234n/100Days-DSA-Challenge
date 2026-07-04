# 13-Graphs

## Topic Introduction
A **Graph** is a non-linear data structure consisting of nodes (vertices) and edges connecting them. Graphs can be directed/undirected, weighted/unweighted, and cyclic/acyclic. Adjacency lists and adjacency matrices are the primary representations.

---

## When to use
- Representing networks (social maps, road paths, web pages linking).
- Dependencies resolution (Topological Sort).
- Finding paths (shortest path algorithms).

---

## Time Complexities
| Algorithm | Time Complexity | Space Complexity | Notes |
| :--- | :---: | :---: | :--- |
| **BFS / DFS** | $O(V + E)$ | $O(V)$ | Traverses all reachable nodes |
| **Dijkstra** | $O((V + E) \log V)$ | $O(V)$ | Single-source shortest path |
| **Kruskal's MST** | $O(E \log E)$ | $O(V)$ | Uses Union-Find |

---

## Common Patterns
1. **BFS (Breadth-First Search)**: Layer traversal, guarantees shortest path on unweighted graphs.
2. **DFS (Depth-First Search)**: Backtracking, connectivity checks, cycle detection.
3. **Union-Find (Disjoint Set)**: Connectivity queries in near constant time, Kruskal's algorithm.
4. **Topological Sort**: Ordering directed acyclic graphs (DAGs) linearly (Kahn's or DFS).

---

## Interview Tips
- Always check for **cycles** by maintaining a visited set. In directed graphs, you also need to track the recursion stack to differentiate between cross edges and cycles.
- When representing graphs in adjacency lists, check if the graph is **1-indexed** or **0-indexed** to size your arrays/lists correctly.

---

## Mistakes to Avoid
- **Infinite Loops**: Forgetting to mark nodes as visited during traversal.

---

## Solved Problems Checklist
- [ ] Number of Islands | **Medium**
- [ ] Clone Graph | **Medium**
- [ ] Course Schedule | **Medium**
