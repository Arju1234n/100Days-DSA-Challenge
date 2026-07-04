from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_to_index:
                return [num_to_index[complement], i]
            num_to_index[num] = i
        return []

# Simple Verification Tests
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1]
    
    # Test Case 2
    assert sol.twoSum([3, 2, 4], 6) == [1, 2]
    
    # Test Case 3
    assert sol.twoSum([3, 3], 6) == [0, 1]
    
    print("Day 1 (Two Sum): All tests passed successfully! 🎉")
