/*
Problem Name: Find All Duplicates in an Array
Platform: LeetCode
Difficulty: Medium

Approach 1: Using the sign-marking trick.
Since the array elements are in the range [1, n] and the array is of size n,
we can use the values as indices. For each number, we go to its corresponding index
and make the element negative. If it is already negative, we found a duplicate.

Time Complexity: O(n)
Space Complexity: O(1) (excluding the space for output array)

Pattern: Arrays
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int idx = std::abs(nums[i]) - 1;

            if (nums[idx] < 0)
                ans.push_back(std::abs(nums[i]));
            else
                nums[idx] *= -1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> result1 = {2, 3};
    std::vector<int> ans1 = sol.findDuplicates(nums1);
    std::sort(ans1.begin(), ans1.end());
    std::sort(result1.begin(), result1.end());
    assert(ans1 == result1);

    // Test Case 2
    std::vector<int> nums2 = {1, 1, 2};
    std::vector<int> result2 = {1};
    std::vector<int> ans2 = sol.findDuplicates(nums2);
    std::sort(ans2.begin(), ans2.end());
    std::sort(result2.begin(), result2.end());
    assert(ans2 == result2);

    // Test Case 3
    std::vector<int> nums3 = {1};
    std::vector<int> result3 = {};
    std::vector<int> ans3 = sol.findDuplicates(nums3);
    assert(ans3 == result3);

    std::cout << "Find All Duplicates in an Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
