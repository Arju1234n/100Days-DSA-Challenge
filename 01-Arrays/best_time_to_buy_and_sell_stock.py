# """
# Problem Name: Best Time to Buy and Sell Stock
# Platform: LeetCode
# Difficulty: Easy
#
# Approach 1: Brute Force checking every pair. O(n^2) time.
# Approach 2: One-pass tracking the min price seen so far and calculating max profit.
# Optimal Approach: One-pass tracking min price.
#
# Time Complexity: O(n)
# Space Complexity: O(1)
#
# Pattern: Dynamic Programming / Greedy / Array
# """

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
            
        min_price = float('inf')
        max_profit = 0
        
        for price in prices:
            if price < min_price:
                min_price = price
            else:
                profit = price - min_price
                max_profit = max(max_profit, profit)
                
        return max_profit

if __name__ == "__main__":
    sol = Solution()
    assert sol.maxProfit([7, 1, 5, 3, 6, 4]) == 5
    print("Best Time to Buy and Sell Stock Python: All tests passed! 🎉")
