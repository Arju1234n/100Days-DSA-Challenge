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

# Simple Verification Tests
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1
    assert sol.maxProfit([7, 1, 5, 3, 6, 4]) == 5
    
    # Test Case 2
    assert sol.maxProfit([7, 6, 4, 3, 1]) == 0
    
    print("Day 5 (Best Time to Buy and Sell Stock): All tests passed successfully! 🎉")
