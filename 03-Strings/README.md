# 03-Strings

## Topic Introduction
A **String** is a sequence of characters, typically stored as a dynamic character array. String manipulation is a key topic in coding interviews, requiring dynamic operations, indexing, and pattern matching.

---

## When to use
- When parsing textual data.
- When matching text patterns (e.g. substrings, anagrams, regex).
- For hashing key generations.

---

## Time Complexities
| Operation | Time Complexity | Notes |
| :--- | :---: | :--- |
| **Concatenation** | $O(n + m)$ | Costly in immutable strings (like Python/Java) |
| **Comparison** | $O(n)$ | Compares character by character |
| **Sub-string Search** | $O(n \cdot m)$ | Brute Force pattern matching |
| **Optimized Search** | $O(n + m)$ | KMP, Rabin-Karp, Z-Algorithm |

---

## Common Patterns
1. **Sliding Window**: Searching for matching substrings or character subsets.
2. **Frequency Map**: Counting char distributions (e.g., anagram checks).
3. **Two Pointers**: Reverse, palindromes, and sequence alignment.
4. **Trie Prefix Trees**: Optimal prefix indexing.

---

## Interview Tips
- Remember that in Python and Java, strings are **immutable**. Operations like slicing or concatenation create copy duplicates, taking $O(n)$ time. Use a list of chars if building string dynamically.
- Check if cases (upper vs lower) and non-alphanumeric chars should be ignored.

---

## Mistakes to Avoid
- **Inefficient concatenation inside loops**: Leads to $O(n^2)$ time complexity.
- **Index out of bounds**: Reading `s[len(s)]`.

---

## Solved Problems Checklist
- [x] [Valid Anagram](./valid_anagram.cpp) | **Easy**
- [ ] Longest Substring Without Repeating Characters | **Medium**
- [ ] Longest Palindromic Substring | **Medium**
- [x] [Reverse a String](./reverse_string.cpp) | **Easy**
- [x] [To Lower Case](./to_lower.cpp) | **Easy**
- [x] [First Unique Character in a String](./first_unique_character.cpp) | **Easy**
- [x] [Sort String](./sort_string.cpp) | **Easy**
- [x] [Check if String is Rotated by Two Places](./rotated_by_two_places.cpp) | **Easy**
- [x] [Add Strings](./add_strings.cpp) | **Easy**
