# 19-Tries

## Topic Introduction
A **Trie** (also called prefix tree) is a special kind of search tree used for storage and retrieval of keys over a character alphabet. Tries are extremely efficient at prefix matching because nodes share common prefixes.

---

## When to use
- Dynamic spell-checking or autocomplete systems.
- Prefix matching (e.g. searching if any word starts with a given prefix).
- Efficient word lookup (e.g. dictionary searches).

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Insert** | $O(L)$ | $L$ is word length |
| **Search Word** | $O(L)$ | Shared prefix traversal |
| **Search Prefix** | $O(L)$ | Verifies paths without reaching termination nodes |

---

## Common Patterns
1. **Word Search / Validation**: Building child arrays of size 26 dynamically to track node branches.
2. **Prefix Counts**: Storing metadata (counts of matching subwords) on intermediate nodes.

---

## Interview Tips
- When implementing a Trie node, include a boolean flag `isEndOfWord` or `isWord` to denote if a node represents the final character of a stored word.
- Using a fixed size child array of pointers/indices (`TrieNode* children[26]`) is fast but consumes space. Alternatively, use a hash map for child nodes to save memory.

---

## Mistakes to Avoid
- **Memory leaks**: In C++, nodes are allocated dynamically. Ensure proper destructor implementations to free allocated children recursively.

---

## Solved Problems Checklist
- [ ] Implement Trie (Prefix Tree) | **Medium**
- [ ] Design Add and Search Words Data Structure | **Medium**
- [ ] Word Search II | **Hard**
