/*
Problem Name: Maximum Product of Three Numbers
Platform: LeetCode
Difficulty: Easy

Approach: Sort the array. The maximum product of three numbers can come from either:
1. The product of the three largest numbers: nums[n-1] * nums[n-2] * nums[n-3]
2. The product of the two smallest (potentially negative) numbers and the largest number: nums[0] * nums[1] * nums[n-1]
Return the maximum of these two products.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) (excluding sorting recursion stack)

Pattern: Arrays / Sorting
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];

        return std::max(product1, product2);
    }
};

int main() {
    Solution sol;

    // Test Case 1: All positive numbers
    std::vector<int> nums1 = {1, 2, 3};
    assert(sol.maximumProduct(nums1) == 6);

    // Test Case 2: Four numbers with positive product
    std::vector<int> nums2 = {1, 2, 3, 4};
    assert(sol.maximumProduct(nums2) == 24);

    // Test Case 3: Negative numbers involved
    std::vector<int> nums3 = {-100, -98, 1, 2, 3, 4};
    assert(sol.maximumProduct(nums3) == 39200);

    // Test Case 4: All negative numbers
    std::vector<int> nums4 = {-1, -2, -3, -4};
    assert(sol.maximumProduct(nums4) == -6);

    std::cout << "Maximum Product of Three Numbers C++: All tests passed! 🎉" << std::endl;
    return 0;
}
