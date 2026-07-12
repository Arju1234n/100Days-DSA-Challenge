/*
Problem Name: Move Zeroes
Platform: LeetCode
Difficulty: Easy

Approach 1: Two Pointers. Maintain a 'left' pointer representing the position where the next non-zero element should go.
Traverse the array with an 'i' pointer. When nums[i] is non-zero, swap it with nums[left] and increment left.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int left = 0;
        
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[left], nums[i]);
                left++;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> nums1 = {0, 1, 0, 3, 12};
    std::vector<int> expected1 = {1, 3, 12, 0, 0};
    sol.moveZeroes(nums1);
    assert(nums1 == expected1);

    // Test Case 2: Only zeros
    std::vector<int> nums2 = {0, 0, 0};
    std::vector<int> expected2 = {0, 0, 0};
    sol.moveZeroes(nums2);
    assert(nums2 == expected2);

    // Test Case 3: No zeros
    std::vector<int> nums3 = {1, 2, 3};
    std::vector<int> expected3 = {1, 2, 3};
    sol.moveZeroes(nums3);
    assert(nums3 == expected3);

    // Test Case 4: Single element zero
    std::vector<int> nums4 = {0};
    std::vector<int> expected4 = {0};
    sol.moveZeroes(nums4);
    assert(nums4 == expected4);

    std::cout << "Move Zeroes C++: All tests passed! 🎉" << std::endl;
    return 0;
}
