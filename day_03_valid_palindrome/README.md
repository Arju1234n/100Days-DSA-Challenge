# Day 3: Valid Palindrome

## Problem Description
A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

### Example 1
```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

### Example 2
```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

---

## Approach (Two Pointers)
We can solve this problem in $O(n)$ time using two pointers without extra memory.
1. Initialize two pointers: `left = 0` at the start of the string, and `right = len(s) - 1` at the end of the string.
2. While `left < right`:
   - If the character at `left` is not alphanumeric, increment `left` pointer.
   - If the character at `right` is not alphanumeric, decrement `right` pointer.
   - If both are alphanumeric, convert them to lowercase and compare:
     - If they are not equal, return `false`.
     - If they are equal, increment `left` and decrement `right` pointers.
3. If the loop completes successfully, return `true`.

### Complexity Analysis
- **Time Complexity:** $O(n)$ where $n$ is the length of string `s`. We traverse the string at most once.
- **Space Complexity:** $O(1)$ since we only use two pointers.
