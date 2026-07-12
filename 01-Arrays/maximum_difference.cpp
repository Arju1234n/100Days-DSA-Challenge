/*
Problem Name: Maximum Difference Between Increasing Elements
Platform: LeetCode
Difficulty: Easy

Approach 1: Iterative tracking of minimum element. Keep track of the minimum element seen so far.
For each element, if it is greater than the minimum element, update the maximum difference. Otherwise, update the minimum element.
Return the maximum difference (or -1 if no such difference exists).
Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Approach 2: Suffix Maximum. Precompute suffix maximums in an array.
For each element, if suffixMax[i] is greater than nums[i], calculate the difference and update the answer.
Time Complexity: O(n)
Space Complexity: O(n) auxiliary space

Pattern: Arrays / Suffix Max / Cumulative Minimum
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    // Approach 1: Minimum element tracking
    int maximumDifference(std::vector<int>& nums) {
        if (nums.empty()) return -1;
        int ans = -1;
        int minelem = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > minelem) {
                ans = std::max(ans, nums[i] - minelem);
            } else {
                minelem = nums[i];
            }
        }

        return ans;
    }

    // Approach 2: Suffix maximum array
    int maximumDifferenceSuffix(std::vector<int>& nums) {
        if (nums.empty()) return -1;
        int n = nums.size();
        std::vector<int> suffixMax(n);
        suffixMax[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = std::max(nums[i], suffixMax[i + 1]);
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (suffixMax[i] > nums[i]) {
                ans = std::max(ans, suffixMax[i] - nums[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> nums1 = {7, 1, 5, 4};
    assert(sol.maximumDifference(nums1) == 4);
    assert(sol.maximumDifferenceSuffix(nums1) == 4);

    // Test Case 2: Decreasing elements
    std::vector<int> nums2 = {9, 4, 3, 2};
    assert(sol.maximumDifference(nums2) == -1);
    assert(sol.maximumDifferenceSuffix(nums2) == -1);

    // Test Case 3: Increasing elements
    std::vector<int> nums3 = {1, 5, 2, 10};
    assert(sol.maximumDifference(nums3) == 9);
    assert(sol.maximumDifferenceSuffix(nums3) == 9);

    std::cout << "Maximum Difference Between Increasing Elements C++: All tests passed! 🎉" << std::endl;
    return 0;
}

