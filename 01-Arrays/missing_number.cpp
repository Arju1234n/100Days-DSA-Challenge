/*
Problem Name: Missing Number
Platform: LeetCode
Difficulty: Easy

Approach 1: Sum formula. The sum of first n numbers is n * (n + 1) / 2. Subtract the sum of all elements in the array from this expected sum to find the missing number.
Optimal Approach: XOR-based. XOR all elements in the array and all numbers from 0 to n. Since a XOR a = 0 and a XOR 0 = a, all numbers present in the array will cancel out, leaving the missing number. This is optimal as it prevents integer overflow.

Time Complexity: O(n) worst and average case, since we do a single pass over the array.
Space Complexity: O(1) auxiliary space

Pattern: Bit Manipulation / Hashing
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int missingNumber(const std::vector<int>& nums) {
        int n = nums.size();
        int xor_sum = n;
        for (int i = 0; i < n; ++i) {
            xor_sum ^= i ^ nums[i];
        }
        return xor_sum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Missing number in the middle
    std::vector<int> nums1 = {3, 0, 1}; // size 3, range [0, 3], missing 2
    assert(sol.missingNumber(nums1) == 2);

    // Test Case 2: Missing number is 0
    std::vector<int> nums2 = {1, 2, 3}; // size 3, range [0, 3], missing 0
    assert(sol.missingNumber(nums2) == 0);

    // Test Case 3: Missing number is n
    std::vector<int> nums3 = {0, 1}; // size 2, range [0, 2], missing 2
    assert(sol.missingNumber(nums3) == 2);

    // Test Case 4: Larger array
    std::vector<int> nums4 = {9, 6, 4, 2, 3, 5, 7, 0, 1}; // missing 8
    assert(sol.missingNumber(nums4) == 8);

    std::cout << "Missing Number C++: All tests passed! 🎉" << std::endl;
    return 0;
}
