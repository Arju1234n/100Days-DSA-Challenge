/*
Problem Name: Perfect Sum Problem (Count Subsets with Target Sum)
Platform: GeeksforGeeks
Difficulty: Medium

Approach: Pure Recursion (Include / Exclude)
  At each index, we have two choices:
    1. NOT TAKE — Skip `arr[idx]` and recurse to `idx + 1` with remaining target `sum`.
    2. TAKE     — If `arr[idx] <= sum`, include `arr[idx]` and recurse to `idx + 1` with `sum - arr[idx]`.

  Base Case:
    - `idx == arr.size()`: Return 1 if `sum == 0` else 0.
      Note: We process all elements up to `idx == arr.size()` to correctly handle 0s in the input array.

Time Complexity : O(2^N) — Exponential recursion tree (2 choices for each element)
Space Complexity: O(N)   — Maximum call stack depth equals N
Pattern: Recursion / Backtracking
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int solve(int idx, int sum, std::vector<int>& arr) {
        if (idx == (int)arr.size()) {
            return (sum == 0);
        }

        int notTake = solve(idx + 1, sum, arr);

        int take = 0;
        if (arr[idx] <= sum) {
            take = solve(idx + 1, sum - arr[idx], arr);
        }

        return take + notTake;
    }

    int perfectSum(std::vector<int>& arr, int sum) {
        return solve(0, sum, arr);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array with multiple matching subsets
    {
        std::vector<int> arr = {5, 2, 3, 10, 6, 8};
        int target = 10; // Subsets: {5, 2, 3}, {10}, {2, 8} -> 3 subsets
        assert(sol.perfectSum(arr, target) == 3);
        std::cout << "Test 1 passed: arr = [5, 2, 3, 10, 6, 8], target = 10 -> 3\n";
    }

    // Test Case 2: Array containing zeros
    {
        std::vector<int> arr = {2, 3, 5, 6, 8, 10};
        int target = 10; // Subsets: {2, 3, 5}, {2, 8}, {10} -> 3 subsets
        assert(sol.perfectSum(arr, target) == 3);
        std::cout << "Test 2 passed: arr = [2, 3, 5, 6, 8, 10], target = 10 -> 3\n";
    }

    // Test Case 3: Array with zero element handling
    {
        std::vector<int> arr = {0, 0, 1};
        int target = 1; // Subsets: {1}, {0, 1}, {0, 1}, {0, 0, 1} -> 4 subsets
        assert(sol.perfectSum(arr, target) == 4);
        std::cout << "Test 3 passed: arr = [0, 0, 1], target = 1 -> 4\n";
    }

    // Test Case 4: Impossible target sum
    {
        std::vector<int> arr = {1, 2, 3};
        int target = 10;
        assert(sol.perfectSum(arr, target) == 0);
        std::cout << "Test 4 passed: arr = [1, 2, 3], target = 10 -> 0\n";
    }

    std::cout << "\nPerfect Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
