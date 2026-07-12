/*
Problem Name: Maximum Subarray (Kadane's Algorithm)
Platform: LeetCode
Difficulty: Medium

Approach 1: Kadane's Algorithm. Keep track of the current maximum subarray sum ending at each position (currentsum)
and the overall maximum subarray sum seen so far (maxsum).
For each element, currentsum = max(nums[i], currentsum + nums[i]). Update maxsum if currentsum is greater.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Pattern: Kadane's Algorithm / Dynamic Programming / Arrays
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int currentsum = nums[0];
        int maxsum = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            currentsum = std::max(nums[i], currentsum + nums[i]);
            maxsum = std::max(currentsum, maxsum);
        }
        return maxsum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard mixed positive and negative numbers
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(sol.maxSubArray(nums1) == 6); // Subarray [4,-1,2,1] has the largest sum = 6.

    // Test Case 2: Single element
    std::vector<int> nums2 = {1};
    assert(sol.maxSubArray(nums2) == 1);

    // Test Case 3: All positive numbers
    std::vector<int> nums3 = {5, 4, -1, 7, 8};
    assert(sol.maxSubArray(nums3) == 23);

    // Test Case 4: All negative numbers
    std::vector<int> nums4 = {-5, -1, -3, -2, -4};
    assert(sol.maxSubArray(nums4) == -1);

    std::cout << "Maximum Subarray C++: All tests passed! 🎉" << std::endl;
    return 0;
}
