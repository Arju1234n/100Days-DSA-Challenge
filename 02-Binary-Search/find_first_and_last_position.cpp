/*
Problem Name: Find First and Last Position of Element in Sorted Array
Platform: LeetCode
Difficulty: Medium

Approach 1: Linear Scan. Traverse the array from left to right to find the first occurrence, and from right to left to find the last occurrence. Time Complexity: O(n).
Optimal Approach: Two Binary Searches. Use binary search to find the first (leftmost) occurrence of the target. Then run another binary search to find the last (rightmost) occurrence of the target. This ensures O(log n) time complexity.

Time Complexity: O(log n) worst and average case, since we run binary search twice.
Space Complexity: O(1) auxiliary space

Pattern: Binary Search / Left-Right Bound
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
private:
    int findBound(const std::vector<int>& nums, int target, bool isFirst) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int bound = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    high = mid - 1; // Look for smaller indices
                } else {
                    low = mid + 1;  // Look for larger indices
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return bound;
    }

public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        int last = findBound(nums, target, false);
        return {first, last};
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target present multiple times
    std::vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    std::vector<int> expected1 = {3, 4};
    assert(sol.searchRange(nums1, 8) == expected1);

    // Test Case 2: Target not present in the range
    std::vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    std::vector<int> expected2 = {-1, -1};
    assert(sol.searchRange(nums2, 6) == expected2);

    // Test Case 3: Empty array
    std::vector<int> nums3 = {};
    std::vector<int> expected3 = {-1, -1};
    assert(sol.searchRange(nums3, 0) == expected3);

    // Test Case 4: Single element array - target present
    std::vector<int> nums4 = {5};
    std::vector<int> expected4 = {0, 0};
    assert(sol.searchRange(nums4, 5) == expected4);

    // Test Case 5: Single element array - target not present
    std::vector<int> nums5 = {5};
    std::vector<int> expected5 = {-1, -1};
    assert(sol.searchRange(nums5, 3) == expected5);

    // Test Case 6: Entire array contains the target
    std::vector<int> nums6 = {2, 2, 2, 2, 2};
    std::vector<int> expected6 = {0, 4};
    assert(sol.searchRange(nums6, 2) == expected6);

    std::cout << "Find First and Last Position of Element in Sorted Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
