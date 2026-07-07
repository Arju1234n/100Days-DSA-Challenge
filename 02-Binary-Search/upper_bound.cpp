/*
Problem Name: Upper Bound in Sorted Array
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Linear Scan. Traverse the array from left to right. The first index where element > target is the upper bound. If all elements are smaller or equal, return n. Time Complexity: O(n).
Optimal Approach: Binary Search. Use binary search to find the upper bound. Maintain a variable `ans` initialized to `n` (since if all elements are smaller or equal, the upper bound is `n`).
If nums[mid] > target, mid is a potential upper bound candidate. Record mid in `ans` and search in the left half (high = mid - 1) to find a smaller index.
If nums[mid] <= target, search in the right half (low = mid + 1).

Time Complexity: O(log n) worst and average case, since we divide the search space by half in each iteration.
Space Complexity: O(1) auxiliary space

Pattern: Binary Search / Upper Bound
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int findUpperBound(const std::vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n; // Default to n if all elements are smaller than or equal to target
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1; // Look for a smaller index on the left
            } else {
                low = mid + 1; // Look on the right
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target present multiple times
    std::vector<int> nums1 = {1, 2, 2, 2, 3, 4};
    assert(sol.findUpperBound(nums1, 2) == 4); // First element > 2 is 3 at index 4

    // Test Case 2: Target present once
    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    assert(sol.findUpperBound(nums2, 3) == 3); // First element > 3 is 4 at index 3

    // Test Case 3: Target not present (smaller than smallest element)
    std::vector<int> nums3 = {4, 5, 6};
    assert(sol.findUpperBound(nums3, 2) == 0); // First element > 2 is 4 at index 0

    // Test Case 4: Target not present (larger than largest element)
    std::vector<int> nums4 = {4, 5, 6};
    assert(sol.findUpperBound(nums4, 8) == 3); // No element > 8, returns n (3)

    // Test Case 5: Empty array
    std::vector<int> nums5 = {};
    assert(sol.findUpperBound(nums5, 5) == 0);

    // Test Case 6: Single element array - target present
    std::vector<int> nums6 = {10};
    assert(sol.findUpperBound(nums6, 10) == 1); // No element > 10, returns n (1)

    // Test Case 7: Single element array - target not present (smaller)
    std::vector<int> nums7 = {10};
    assert(sol.findUpperBound(nums7, 5) == 0); // First element > 5 is 10 at index 0

    // Test Case 8: Single element array - target not present (larger)
    std::vector<int> nums8 = {10};
    assert(sol.findUpperBound(nums8, 15) == 1);

    // Test Case 9: Element in middle not present
    std::vector<int> nums9 = {1, 3, 5, 6};
    assert(sol.findUpperBound(nums9, 2) == 1); // first element > 2 is 3 at index 1

    std::cout << "Upper Bound C++: All tests passed! 🎉" << std::endl;
    return 0;
}
