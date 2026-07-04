# Day 1: Two Sum

## Problem Description
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

### Example 1
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

---

## Approach (One-Pass Hash Map)
We can solve this problem in $O(n)$ time using a hash map (dictionary in Python).
1. We iterate through the array, keeping track of the index and the value of each element.
2. For each element `num`, we calculate its complement: `complement = target - num`.
3. We check if the complement already exists in our hash map.
   - If it does, we have found the two numbers. We return their indices: `[hash_map[complement], current_index]`.
   - If it doesn't, we add the current element and its index to the hash map and continue.

### Complexity Analysis
- **Time Complexity:** $O(n)$ where $n$ is the number of elements in the array. We traverse the list containing $n$ elements only once.
- **Space Complexity:** $O(n)$ because we store at most $n$ elements in the hash map.
