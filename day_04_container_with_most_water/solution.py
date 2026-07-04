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

# Simple Verification Tests
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1
    assert sol.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    
    # Test Case 2
    assert sol.maxArea([1, 1]) == 1
    
    print("Day 4 (Container With Most Water): All tests passed successfully! 🎉")
