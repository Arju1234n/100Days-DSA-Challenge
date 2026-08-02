/*
Problem Name: 3Sum Closest
Platform: LeetCode
Difficulty: Medium

Approach: Sort the array. Fix the first element using a loop, then use two pointers (left and right) to find the triplet sum closest to the target. Update closest sum whenever a closer sum is found.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding space for sorting)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                // Update closest sum
                if (std::abs(target - total) < std::abs(target - closest)) {
                    closest = total;
                }

                if (total < target) {
                    left++;
                } else if (total > target) {
                    right--;
                } else {
                    return total;
                }
            }
        }

        return closest;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    assert(sol.threeSumClosest(nums1, target1) == 2);

    // Test Case 2
    std::vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    assert(sol.threeSumClosest(nums2, target2) == 0);

    // Test Case 3
    std::vector<int> nums3 = {1, 1, 1, 0};
    int target3 = -100;
    assert(sol.threeSumClosest(nums3, target3) == 2);

    std::cout << "3Sum Closest C++: All tests passed! 🎉" << std::endl;
    return 0;
}
