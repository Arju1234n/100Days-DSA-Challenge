# Day 5: Best Time to Buy and Sell Stock

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i-th` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

### Example 1
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

---

## Approach (One-Pass Min Price Tracker)
We can solve this problem in $O(n)$ time using a single pass.
1. Keep track of the `min_price` seen so far. Initialize `min_price` to infinity.
2. Keep track of the `max_profit`. Initialize `max_profit = 0`.
3. Iterate through each `price` in `prices`:
   - If the current `price` is less than `min_price`, update `min_price = price`.
   - Otherwise, calculate the potential profit: `profit = price - min_price`.
   - Update `max_profit = max(max_profit, profit)`.
4. Return `max_profit`.

### Complexity Analysis
- **Time Complexity:** $O(n)$ where $n$ is the length of `prices`. We traverse the array once.
- **Space Complexity:** $O(1)$ since we only use a couple of variables to keep track of state.
