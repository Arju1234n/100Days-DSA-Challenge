# """
# Problem Name: Two Sum
# Platform: LeetCode
# Difficulty: Easy
#
# Approach 1: Brute Force double loop.
# Approach 2: None.
# Optimal Approach: One-pass hash map mapping visited values to their indices.
#
# Time Complexity: O(n)
# Space Complexity: O(n)
#
# Pattern: Hashing
# """

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

if __name__ == "__main__":
    sol = Solution()
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert sol.twoSum([3, 2, 4], 6) == [1, 2]
    print("Two Sum Python: All tests passed! 🎉")
