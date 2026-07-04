# Day 4: Container With Most Water

## Problem Description
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Notice** that you may not slant the container.

### Example 1
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water the container can contain is 49.
```

---

## Approach (Two Pointers)
We can solve this problem in $O(n)$ time using two pointers.
1. Initialize two pointers: `left = 0` and `right = len(height) - 1`.
2. Keep track of the `max_area = 0`.
3. While `left < right`:
   - Calculate the width: `width = right - left`.
   - Calculate the height of the container, which is limited by the shorter line: `h = min(height[left], height[right])`.
   - Compute the current area: `current_area = width * h`.
   - Update `max_area = max(max_area, current_area)`.
   - To maximize the area, we want to find taller lines. Therefore, move the pointer pointing to the shorter line:
     - If `height[left] < height[right]`, increment `left`.
     - Else, decrement `right`.
4. Return `max_area`.

### Complexity Analysis
- **Time Complexity:** $O(n)$ where $n$ is the number of lines. We scan the array at most once.
- **Space Complexity:** $O(1)$ since only constant extra space is used.
