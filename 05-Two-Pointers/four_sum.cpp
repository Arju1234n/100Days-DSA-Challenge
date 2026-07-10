/*
Problem Name: 4Sum
Platform: LeetCode
Difficulty: Medium

Approach 1: Brute Force checking all quadruplets. Time: O(n^4), Space: O(1).
Approach 2: Hashing (using a hash map to store pairs and their sums). Time: O(n^2), Space: O(n^2).
Optimal Approach: Sort and Two Pointers. Fix the first two elements with nested loops, and use two pointers for the remaining two elements. Skip duplicates at each step and use long long to prevent integer overflow. Time: O(n^3), Space: O(1) (excluding sorting space).

Time Complexity: O(n^3)
Space Complexity: O(1) (ignoring sorting recursion stack)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) {
            return result;
        }
        
        // Sort the array first
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move pointers and skip duplicates
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case with multiple quadruplets and target = 0
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> expected1 = {
        {-2, -1, 1, 2},
        {-2, 0, 0, 2},
        {-1, 0, 0, 1}
    };
    std::vector<std::vector<int>> result1 = sol.fourSum(nums1, 0);
    std::sort(result1.begin(), result1.end());
    std::sort(expected1.begin(), expected1.end());
    assert(result1 == expected1);
    
    // Test Case 2: Target = 8, unique values
    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    std::vector<std::vector<int>> expected2 = {
        {2, 2, 2, 2}
    };
    std::vector<std::vector<int>> result2 = sol.fourSum(nums2, 8);
    assert(result2 == expected2);

    std::cout << "4Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
