/*
Problem Name: Kth Largest Element in an Array
Platform: LeetCode (215)
Difficulty: Medium

Approach 1: Sort the array in ascending order and return the element at index (n - k).

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) auxiliary space (or O(log n) for std::sort recursion stack).

Pattern: Sorting / Heap
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - k];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    assert(sol.findKthLargest(nums1, k1) == 5);

    // Test Case 2: Array with duplicates
    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    assert(sol.findKthLargest(nums2, k2) == 4);

    // Test Case 3: k = 1 (Largest element)
    std::vector<int> nums3 = {7, 10, 4, 3, 20, 15};
    int k3 = 1;
    assert(sol.findKthLargest(nums3, k3) == 20);

    // Test Case 4: k = N (Smallest element)
    std::vector<int> nums4 = {7, 10, 4, 3, 20, 15};
    int k4 = 6;
    assert(sol.findKthLargest(nums4, k4) == 3);

    std::cout << "Kth Largest Element in an Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
