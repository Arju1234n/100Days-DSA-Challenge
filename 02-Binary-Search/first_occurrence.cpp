/*
Problem Name: First Occurrence in Sorted
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Linear Scan. Traverse the array from left to right. The first index where element equals target is the first occurrence. Time Complexity: O(n).
Optimal Approach: Binary Search. Keep track of the first occurrence index. When target equals nums[mid], record the index mid and shift the search boundary to the left half (high = mid - 1) to see if there are any earlier occurrences.

Time Complexity: O(log n) worst and average case, since we divide the search space by half in each iteration.
Space Complexity: O(1) auxiliary space

Pattern: Binary Search / Left Bound
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int findFirstOccurrence(const std::vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                high = mid - 1; // Move left to find first occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target present multiple times
    std::vector<int> nums1 = {1, 2, 2, 2, 3, 4};
    assert(sol.findFirstOccurrence(nums1, 2) == 1);

    // Test Case 2: Target present once
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    assert(sol.findFirstOccurrence(nums2, 3) == 2);

    // Test Case 3: Target not present (smaller than smallest element)
    std::vector<int> nums3 = {4, 5, 6};
    assert(sol.findFirstOccurrence(nums3, 2) == -1);

    // Test Case 4: Target not present (larger than largest element)
    std::vector<int> nums4 = {4, 5, 6};
    assert(sol.findFirstOccurrence(nums4, 8) == -1);

    // Test Case 5: Empty array
    std::vector<int> nums5 = {};
    assert(sol.findFirstOccurrence(nums5, 5) == -1);

    // Test Case 6: Single element array - target present
    std::vector<int> nums6 = {10};
    assert(sol.findFirstOccurrence(nums6, 10) == 0);

    // Test Case 7: Single element array - target not present
    std::vector<int> nums7 = {10};
    assert(sol.findFirstOccurrence(nums7, 5) == -1);

    std::cout << "First Occurrence in Sorted C++: All tests passed! 🎉" << std::endl;
    return 0;
}
