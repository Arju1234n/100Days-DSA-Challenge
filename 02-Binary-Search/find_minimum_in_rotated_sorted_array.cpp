/*
Problem Name: Find Minimum in Rotated Sorted Array
Platform: LeetCode
Difficulty: Medium

Approach: Binary Search. Since the array is rotated and sorted, we can find the pivot element (the minimum element) in O(log n) time.
We initialize `low = 0` and `high = nums.size() - 1`. In each step, we look at the middle element `mid`:
- If `nums[mid] > nums[high]`, the inflection point (minimum) must lie to the right of `mid` (e.g., [4, 5, 6, 7, 0, 1, 2] where mid is 7 and high is 2). Thus, we set `low = mid + 1`.
- If `nums[mid] <= nums[high]`, the right half is sorted, and the minimum element is either at `mid` or to the left of `mid`. Thus, we set `high = mid`.
The loop terminates when `low == high`, leaving us with the index of the minimum element.

Time Complexity: O(log n) worst and average case, since the search space is halved in each step.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search / Rotated Sorted Array / Pivot Finding
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is greater than the last element, the minimum is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Otherwise, the minimum is in the left half including mid
            else {
                high = mid;
            }
        }
        
        return nums[low];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Minimum in the middle
    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    assert(sol.findMin(nums1) == 1);

    // Test Case 2: Minimum towards the right
    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    assert(sol.findMin(nums2) == 0);

    // Test Case 3: Fully sorted (0 rotations)
    std::vector<int> nums3 = {11, 13, 15, 17};
    assert(sol.findMin(nums3) == 11);

    // Test Case 4: Single element array
    std::vector<int> nums4 = {1};
    assert(sol.findMin(nums4) == 1);

    // Test Case 5: Two elements, rotated
    std::vector<int> nums5 = {2, 1};
    assert(sol.findMin(nums5) == 1);

    // Test Case 6: Two elements, sorted
    std::vector<int> nums6 = {1, 2};
    assert(sol.findMin(nums6) == 1);

    std::cout << "Find Minimum in Rotated Sorted Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
