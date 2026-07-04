# Day 2: Valid Anagram

## Problem Description
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Example 1
```
Input: s = "anagram", t = "nagaram"
Output: true
```

### Example 2
```
Input: s = "rat", t = "car"
Output: false
```

---

## Approach (Frequency Count / Hash Map)
We can solve this problem in $O(n)$ time using a hash map or integer array to keep track of character frequencies.
1. If the lengths of `s` and `t` are different, they cannot be anagrams of each other, so we return `false` immediately.
2. We can count the frequency of characters in `s` and subtract the frequency of characters in `t`.
3. If all character counts in our frequency table/dictionary are exactly zero, `t` is a valid anagram of `s`.

### Complexity Analysis
- **Time Complexity:** $O(n)$ where $n$ is the length of string `s` (or `t`). We traverse each string once.
- **Space Complexity:** $O(1)$ since the table size is constant (at most 26 lowercase English letters or a fixed character set).
