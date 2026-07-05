/*
Problem Name: Sum of Unique Elements
Platform: LeetCode
Difficulty: Easy

Approach 1: Frequency count. Traverse the array and store the frequency of each element in a hash map. Then, sum all the elements that have a frequency of exactly 1.

Time Complexity: O(n) worst and average case, where n is the number of elements in the array.
Space Complexity: O(n) auxiliary space to store the frequency map.

Pattern: Hashing
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    int sumOfUnique(const std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        int sum = 0;
        for (const auto& [num, count] : counts) {
            if (count == 1) {
                sum += num;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Some elements are unique
    std::vector<int> nums1 = {1, 2, 3, 2};
    assert(sol.sumOfUnique(nums1) == 4); // 1 and 3 are unique -> 1 + 3 = 4

    // Test Case 2: All elements are duplicates
    std::vector<int> nums2 = {1, 1, 1, 1, 1};
    assert(sol.sumOfUnique(nums2) == 0); // No unique elements -> 0

    // Test Case 3: All elements are unique
    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    assert(sol.sumOfUnique(nums3) == 15); // All elements unique -> 1+2+3+4+5 = 15

    // Test Case 4: Empty array
    std::vector<int> nums4 = {};
    assert(sol.sumOfUnique(nums4) == 0);

    // Test Case 5: Single element
    std::vector<int> nums5 = {10};
    assert(sol.sumOfUnique(nums5) == 10);

    std::cout << "Sum of Unique Elements C++: All tests passed! 🎉" << std::endl;
    return 0;
}
