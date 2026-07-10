/*
Problem Name: Search in Rotated Sorted Array
Platform: LeetCode
Difficulty: Medium

Approach: Binary Search. Although the array is rotated, one of the two halves (left or right) around the middle element `mid` will always be sorted.
We can check which half is sorted:
1. If `nums[low] <= nums[mid]`, then the left half is sorted.
   - If `target` lies within the range of the sorted left half (`nums[low] <= target < nums[mid]`), we search in the left half (`high = mid - 1`).
   - Otherwise, we search in the right half (`low = mid + 1`).
2. If the left half is not sorted, then the right half must be sorted.
   - If `target` lies within the range of the sorted right half (`nums[mid] < target <= nums[high]`), we search in the right half (`low = mid + 1`).
   - Otherwise, we search in the left half (`high = mid - 1`).

Time Complexity: O(log n) worst and average case, since the search space is halved in each step.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search / Rotated Sorted Array
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // target is in the left sorted half
                } else {
                    low = mid + 1;  // target is in the right half
                }
            } 
            // Otherwise, right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // target is in the right sorted half
                } else {
                    high = mid - 1; // target is in the left half
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target present in left sorted part
    std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums1, 6) == 2);

    // Test Case 2: Target present in right sorted part
    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums2, 0) == 4);

    // Test Case 3: Target not present
    std::vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.search(nums3, 3) == -1);

    // Test Case 4: Target not present, single element
    std::vector<int> nums4 = {1};
    assert(sol.search(nums4, 0) == -1);

    // Test Case 5: Target present, single element
    std::vector<int> nums5 = {1};
    assert(sol.search(nums5, 1) == 0);

    // Test Case 6: Fully sorted array (0 rotation)
    std::vector<int> nums6 = {1, 3, 5};
    assert(sol.search(nums6, 3) == 1);

    std::cout << "Search in Rotated Sorted Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
