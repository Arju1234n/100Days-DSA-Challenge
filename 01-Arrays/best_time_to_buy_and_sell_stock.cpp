/*
Problem Name: Best Time to Buy and Sell Stock
Platform: LeetCode
Difficulty: Easy

Approach 1: Brute Force calculating profit for all possible buy/sell day pairs (O(n^2) time).
Approach 2: Min-price tracker keeping track of the minimum price seen so far and maximizing profit.
Optimal Approach: One-pass Min-price tracker.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Dynamic Programming / Greedy / Array
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
            } else {
                int profit = price - min_price;
                max_profit = std::max(max_profit, profit);
            }
        }
        
        return max_profit;
    }
};

int main() {
    Solution sol;
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(sol.maxProfit(prices1) == 5);
    std::cout << "Best Time to Buy and Sell Stock C++: All tests passed! 🎉" << std::endl;
    return 0;
}
