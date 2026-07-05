/*
Problem Name: Reverse Array
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Reverse array in-place using two pointers. Initialize one pointer at the start (left = 0) and one at the end (right = n-1). Swap the elements at these pointers, then increment left and decrement right, repeating until they meet or cross.

Time Complexity: O(n) worst and average case, as we iterate n/2 times.
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: Odd length array
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> expected1 = {5, 4, 3, 2, 1};
    sol.reverseArray(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Even length array
    std::vector<int> arr2 = {10, 20, 30, 40};
    std::vector<int> expected2 = {40, 30, 20, 10};
    sol.reverseArray(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Single element array
    std::vector<int> arr3 = {42};
    std::vector<int> expected3 = {42};
    sol.reverseArray(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Empty array
    std::vector<int> arr4 = {};
    std::vector<int> expected4 = {};
    sol.reverseArray(arr4);
    assert(arr4 == expected4);

    // Test Case 5: Array with duplicate elements
    std::vector<int> arr5 = {1, 1, 2, 1, 1};
    std::vector<int> expected5 = {1, 1, 2, 1, 1};
    sol.reverseArray(arr5);
    assert(arr5 == expected5);

    std::cout << "Reverse Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
