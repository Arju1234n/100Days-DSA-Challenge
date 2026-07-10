/*
Problem Name: Two Sum II - Input Array Is Sorted
Platform: LeetCode
Difficulty: Medium

Approach 1: Brute Force checking all pairs. Time: O(n^2), Space: O(1).
Approach 2: Binary Search for complement. Time: O(n log n), Space: O(1).
Optimal Approach: Two Pointers from both ends. Since array is sorted, we can increment left or decrement right to find the target. Time: O(n), Space: O(1).

Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum == target) {
                return {left + 1, right + 1}; // 1-based indexing as per LeetCode description
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case
    std::vector<int> nums1 = {2, 7, 11, 15};
    std::vector<int> result1 = {1, 2};
    assert(sol.twoSum(nums1, 9) == result1);
    
    // Test Case 2: Target is 6, elements are 2, 3, 4
    std::vector<int> nums2 = {2, 3, 4};
    std::vector<int> result2 = {1, 3};
    assert(sol.twoSum(nums2, 6) == result2);
    
    // Test Case 3: Negative numbers
    std::vector<int> nums3 = {-1, 0};
    std::vector<int> result3 = {1, 2};
    assert(sol.twoSum(nums3, -1) == result3);

    std::cout << "Two Sum II (Sorted Array) C++: All tests passed! 🎉" << std::endl;
    return 0;
}
