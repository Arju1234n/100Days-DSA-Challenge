/*
Problem Name: Split an Array into Two Equal Sum Subarrays
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Calculate total sum first, then iterate through the array maintaining a running left sum.
At each index (except the last), calculate rightSum = total - leftSum. If leftSum == rightSum, return true.
If the loop finishes without finding such a point, return false.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Pattern: Prefix Sum / Cumulative Sum
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

class Solution {
public:
    bool canSplit(std::vector<int>& arr) {
        int total = 0;
        for (int x : arr)
            total += x;

        int leftSum = 0;

        for (size_t i = 0; i < arr.size() - 1; i++) {
            leftSum += arr[i];
            int rightSum = total - leftSum;

            if (leftSum == rightSum)
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Can be split as [1, 2, 3] (sum 6) and [6] (sum 6)
    std::vector<int> arr1 = {1, 2, 3, 6};
    assert(sol.canSplit(arr1) == true);

    // Test Case 2: Cannot be split equally
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    assert(sol.canSplit(arr2) == false);

    // Test Case 3: Can be split as [4] (sum 4) and [1, 2, 1] (sum 4)
    std::vector<int> arr3 = {4, 1, 2, 1};
    assert(sol.canSplit(arr3) == true);

    std::cout << "Split Array Equal Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
