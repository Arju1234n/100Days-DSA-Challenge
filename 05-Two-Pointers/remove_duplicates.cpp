/*
Problem Name: Remove Duplicates from Sorted Array
Platform: LeetCode
Difficulty: Easy

Approach 1: Two Pointers (Slow and Fast). Maintain a 'slow' pointer pointing to the last unique element found.
Iterate with a 'fast' pointer. When nums[fast] is different from nums[slow], increment slow and copy nums[fast] to nums[slow].
Return slow + 1.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (size_t fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard sorted array with duplicates
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> expected1 = {1, 2};
    int k1 = sol.removeDuplicates(nums1);
    assert(k1 == 2);
    for (int i = 0; i < k1; i++) {
        assert(nums1[i] == expected1[i]);
    }

    // Test Case 2: Multi-duplicate array
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> expected2 = {0, 1, 2, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    assert(k2 == 5);
    for (int i = 0; i < k2; i++) {
        assert(nums2[i] == expected2[i]);
    }

    // Test Case 3: Empty array
    std::vector<int> nums3 = {};
    int k3 = sol.removeDuplicates(nums3);
    assert(k3 == 0);

    // Test Case 4: Already unique elements
    std::vector<int> nums4 = {1, 2, 3};
    std::vector<int> expected4 = {1, 2, 3};
    int k4 = sol.removeDuplicates(nums4);
    assert(k4 == 3);
    for (int i = 0; i < k4; i++) {
        assert(nums4[i] == expected4[i]);
    }

    std::cout << "Remove Duplicates from Sorted Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
