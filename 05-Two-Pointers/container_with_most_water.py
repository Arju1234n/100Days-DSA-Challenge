# """
# Problem Name: Container With Most Water
# Platform: LeetCode
# Difficulty: Medium
#
# Approach 1: Brute Force checking every pair. O(n^2) time.
# Approach 2: Two pointers starting at both ends, moving the pointer pointing to the shorter line inward.
# Optimal Approach: Two pointers.
#
# Time Complexity: O(n)
# Space Complexity: O(1)
#
# Pattern: Two Pointers
# """

from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_area = 0
        
        while left < right:
            width = right - left
            h = min(height[left], height[right])
            current_area = width * h
            max_area = max(max_area, current_area)
            
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return max_area

if __name__ == "__main__":
    sol = Solution()
    assert sol.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    print("Container With Most Water Python: All tests passed! 🎉")
