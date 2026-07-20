/*
Problem Name: Subset Sum Problem
Platform: GeeksforGeeks
Difficulty: Medium

Approach: Pure Recursion (Include / Exclude)
  At each index, we have two choices:
    1. EXCLUDE — Skip the current element `arr[idx]` and check if target `sum` can be formed using remaining elements.
    2. INCLUDE — If `arr[idx] <= sum`, include `arr[idx]` and search for `sum - arr[idx]` in remaining elements.

  Base Cases:
    - `sum == 0`: Target sum achieved -> return true.
    - `idx == arr.size()`: Processed all elements without reaching target sum -> return false.

Time Complexity : O(2^N) — Exponential recursion tree with 2 choices per element
Space Complexity: O(N)   — Maximum call stack depth equals N
Pattern: Recursion / Backtracking
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    bool solve(int idx, int sum, std::vector<int>& arr) {
        if (sum == 0)
            return true;

        if (idx == (int)arr.size())
            return false;

        // Exclude current element
        if (solve(idx + 1, sum, arr))
            return true;

        // Include current element if valid
        if (arr[idx] <= sum) {
            if (solve(idx + 1, sum - arr[idx], arr))
                return true;
        }

        return false;
    }

    bool isSubsetSum(std::vector<int>& arr, int sum) {
        return solve(0, sum, arr);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case with target sum existing
    {
        std::vector<int> arr = {3, 34, 4, 12, 5, 2};
        int target = 9; // 4 + 5 = 9 or 3 + 4 + 2 = 9
        assert(sol.isSubsetSum(arr, target) == true);
        std::cout << "Test 1 passed: arr = [3, 34, 4, 12, 5, 2], target = 9 -> true\n";
    }

    // Test Case 2: Target sum impossible
    {
        std::vector<int> arr = {3, 34, 4, 12, 5, 2};
        int target = 30;
        assert(sol.isSubsetSum(arr, target) == false);
        std::cout << "Test 2 passed: arr = [3, 34, 4, 12, 5, 2], target = 30 -> false\n";
    }

    // Test Case 3: Target is 0
    {
        std::vector<int> arr = {1, 2, 3};
        int target = 0;
        assert(sol.isSubsetSum(arr, target) == true);
        std::cout << "Test 3 passed: arr = [1, 2, 3], target = 0 -> true\n";
    }

    // Test Case 4: Single element equal to target
    {
        std::vector<int> arr = {5};
        int target = 5;
        assert(sol.isSubsetSum(arr, target) == true);
        std::cout << "Test 4 passed: arr = [5], target = 5 -> true\n";
    }

    // Test Case 5: Single element smaller than target
    {
        std::vector<int> arr = {5};
        int target = 10;
        assert(sol.isSubsetSum(arr, target) == false);
        std::cout << "Test 5 passed: arr = [5], target = 10 -> false\n";
    }

    std::cout << "\nSubset Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
