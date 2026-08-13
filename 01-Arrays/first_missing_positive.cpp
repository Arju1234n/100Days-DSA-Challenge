/*
Problem Name: First Missing Positive / Smallest Positive Missing Number
Platform: LeetCode / GeeksforGeeks
Difficulty: Medium

Approach: Cycle Sort / In-place Hash Map (Indexing)
Place each positive number x in the range [1, n] at index x - 1 using swaps.
After placement, iterate through the array to find the first index i where arr[i] != i + 1.
The smallest missing positive number is i + 1. If all 1..n are present, return n + 1.

Time Complexity: O(n) - Each element is placed in its correct position at most once.
Space Complexity: O(1) auxiliary space

Pattern: Cycle Sort / Array Indexing
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int> &arr) {

        int n = arr.size();

        for(int i = 0; i < n; i++) {

            while(arr[i] >= 1 &&
                  arr[i] <= n &&
                  arr[arr[i] - 1] != arr[i]) {

                std::swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {

            if(arr[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }

    int firstMissingPositive(std::vector<int> &nums) {
        return missingNumber(nums);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Unsorted with negatives and duplicates
    std::vector<int> arr1 = {2, -3, 4, 1, 1, 7};
    assert(sol.missingNumber(arr1) == 3);

    // Test Case 2: Array missing a number in between
    std::vector<int> arr2 = {5, 3, 2, 5, 1};
    assert(sol.missingNumber(arr2) == 4);

    // Test Case 3: All non-positive elements
    std::vector<int> arr3 = {-8, 0, -1, -4, -3};
    assert(sol.missingNumber(arr3) == 1);

    // Test Case 4: Consecutive 1 to n present
    std::vector<int> arr4 = {1, 2, 3, 4, 5};
    assert(sol.missingNumber(arr4) == 6);

    // Test Case 5: Single element 1
    std::vector<int> arr5 = {1};
    assert(sol.missingNumber(arr5) == 2);

    // Test Case 6: Single element 2
    std::vector<int> arr6 = {2};
    assert(sol.missingNumber(arr6) == 1);

    std::cout << "First Missing Positive C++: All tests passed! 🎉" << std::endl;
    return 0;
}
