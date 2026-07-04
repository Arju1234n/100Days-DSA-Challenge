/*
Problem Name: Two Sum
Platform: LeetCode
Difficulty: Easy

Approach 1: Brute Force double loop checking all pairs.
Approach 2: None.
Optimal Approach: One-pass Hash Map tracking visited numbers and their indices.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern: Hashing
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    std::vector<int> result1 = {0, 1};
    assert(sol.twoSum(nums1, 9) == result1);
    
    // Test Case 2
    std::vector<int> nums2 = {3, 2, 4};
    std::vector<int> result2 = {1, 2};
    assert(sol.twoSum(nums2, 6) == result2);
    
    std::cout << "Two Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
