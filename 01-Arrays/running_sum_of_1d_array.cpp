/*
Problem Name: Running Sum of 1d Array
Platform: LeetCode
Difficulty: Easy

Approach 1: Prefix Sum (In-place). Traverse the array starting from index 1, updating nums[i] += nums[i-1].
Optimal Approach: Prefix Sum (In-place) / Cumulative Sum.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Prefix Sum
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 2, 3, 4]
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<int> expected1 = {1, 3, 6, 10};
    assert(sol.runningSum(nums1) == expected1);

    // Test Case 2: [1, 1, 1, 1, 1]
    std::vector<int> nums2 = {1, 1, 1, 1, 1};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    assert(sol.runningSum(nums2) == expected2);

    // Test Case 3: [3, 1, 2, 10, 1]
    std::vector<int> nums3 = {3, 1, 2, 10, 1};
    std::vector<int> expected3 = {3, 4, 6, 16, 17};
    assert(sol.runningSum(nums3) == expected3);

    std::cout << "Running Sum of 1d Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
