/*
Problem Name: Search Insert Position
Platform: LeetCode
Difficulty: Easy

Approach 1: Linear Scan. Traverse the array from left to right. The first index where element >= target is the insert position. If we reach the end, the insert position is n. Time Complexity: O(n).
Optimal Approach: Binary Search. Use binary search to find the target. If target is found at mid, return mid. If the search finishes without finding target, the lower pointer (low) will point to the index where target should be inserted to maintain order.

Time Complexity: O(log n) worst and average case, since we divide the search space by half in each iteration.
Space Complexity: O(1) auxiliary space

Pattern: Binary Search / Lower Bound
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target is present in the array
    std::vector<int> nums1 = {1, 3, 5, 6};
    assert(sol.searchInsert(nums1, 5) == 2);

    // Test Case 2: Target is not present and should be in the middle
    std::vector<int> nums2 = {1, 3, 5, 6};
    assert(sol.searchInsert(nums2, 2) == 1);

    // Test Case 3: Target is not present and should be at the end
    std::vector<int> nums3 = {1, 3, 5, 6};
    assert(sol.searchInsert(nums3, 7) == 4);

    // Test Case 4: Target is not present and should be at the beginning
    std::vector<int> nums4 = {1, 3, 5, 6};
    assert(sol.searchInsert(nums4, 0) == 0);

    // Test Case 5: Empty array
    std::vector<int> nums5 = {};
    assert(sol.searchInsert(nums5, 5) == 0);

    // Test Case 6: Single element array - target present
    std::vector<int> nums6 = {10};
    assert(sol.searchInsert(nums6, 10) == 0);

    // Test Case 7: Single element array - target not present (less than)
    std::vector<int> nums7 = {10};
    assert(sol.searchInsert(nums7, 5) == 0);

    // Test Case 8: Single element array - target not present (greater than)
    std::vector<int> nums8 = {10};
    assert(sol.searchInsert(nums8, 15) == 1);

    std::cout << "Search Insert Position C++: All tests passed! 🎉" << std::endl;
    return 0;
}
