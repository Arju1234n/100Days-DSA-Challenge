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
    
    // Test Case 1
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(sol.maxProfit(prices1) == 5);
    
    // Test Case 2
    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    assert(sol.maxProfit(prices2) == 0);
    
    std::cout << "Day 5 (Best Time to Buy and Sell Stock) C++: All tests passed successfully! 🎉" << std::endl;
    return 0;
}
