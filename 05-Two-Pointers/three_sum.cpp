/*
Problem Name: 3Sum
Platform: LeetCode
Difficulty: Medium

Approach 1: Brute Force checking all triplets. Time: O(n^3), Space: O(1).
Approach 2: Hashing (using a set/map to find the third element). Time: O(n^2), Space: O(n).
Optimal Approach: Sort and Two Pointers. Fix the first element and use two pointers to find the other two. Skip duplicates. Time: O(n^2), Space: O(1) (excluding sorting space).

Time Complexity: O(n^2)
Space Complexity: O(1) (ignoring sorting recursion stack)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Sort the array first
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers and skip duplicates
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case with multiple triplets and duplicates
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected1 = {
        {-1, -1, 2},
        {-1, 0, 1}
    };
    std::vector<std::vector<int>> result1 = sol.threeSum(nums1);
    // Sort results to ensure order-independent assertion
    std::sort(result1.begin(), result1.end());
    std::sort(expected1.begin(), expected1.end());
    assert(result1 == expected1);
    
    // Test Case 2: No triplets sum to 0
    std::vector<int> nums2 = {0, 1, 1};
    std::vector<std::vector<int>> expected2 = {};
    assert(sol.threeSum(nums2) == expected2);
    
    // Test Case 3: Exactly one triplet sums to 0
    std::vector<int> nums3 = {0, 0, 0};
    std::vector<std::vector<int>> expected3 = {{0, 0, 0}};
    assert(sol.threeSum(nums3) == expected3);

    std::cout << "3Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
