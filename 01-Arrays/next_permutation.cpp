/*
Problem Name: Next Permutation
Platform: LeetCode
Difficulty: Medium

Approach:
1. Find the breakpoint `index` from the right where `nums[i] < nums[i + 1]`.
2. If no such breakpoint exists (array is sorted descending), reverse the entire array to get the smallest permutation.
3. If breakpoint exists, find the smallest element greater than `nums[index]` from the right and swap them.
4. Reverse the suffix starting from `index + 1` to get the next lexicographically greater permutation.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Arrays / Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find breakpoint
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse whole array
        if (index == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find next greater element from right
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                std::swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        std::reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> expected1 = {1, 3, 2};
    sol.nextPermutation(nums1);
    assert(nums1 == expected1);

    // Test Case 2: Descending order (last permutation -> wraps to first)
    std::vector<int> nums2 = {3, 2, 1};
    std::vector<int> expected2 = {1, 2, 3};
    sol.nextPermutation(nums2);
    assert(nums2 == expected2);

    // Test Case 3: Duplicate elements
    std::vector<int> nums3 = {1, 1, 5};
    std::vector<int> expected3 = {1, 5, 1};
    sol.nextPermutation(nums3);
    assert(nums3 == expected3);

    // Test Case 4: Larger array
    std::vector<int> nums4 = {1, 3, 2};
    std::vector<int> expected4 = {2, 1, 3};
    sol.nextPermutation(nums4);
    assert(nums4 == expected4);

    std::cout << "Next Permutation C++: All tests passed! 🎉" << std::endl;
    return 0;
}
