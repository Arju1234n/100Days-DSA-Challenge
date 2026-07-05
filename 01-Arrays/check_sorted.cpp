/*
Problem Name: Check if Array is Sorted
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Traverse the array from left to right. For each element at index i, check if it is greater than the element at index i + 1. If we find any such pair, the array is not sorted. If no such pair exists, the array is sorted.

Time Complexity: O(n) worst and average case, O(1) best case (when first out-of-order element is at the start)
Space Complexity: O(1) auxiliary space

Pattern: Linear Scan
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    bool isSorted(const std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Sorted array (strictly increasing)
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    assert(sol.isSorted(arr1) == true);

    // Test Case 2: Sorted array (with duplicates)
    std::vector<int> arr2 = {1, 2, 2, 3, 3, 4};
    assert(sol.isSorted(arr2) == true);

    // Test Case 3: Unsorted array
    std::vector<int> arr3 = {1, 3, 2, 4, 5};
    assert(sol.isSorted(arr3) == false);

    // Test Case 4: Reverse sorted array
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    assert(sol.isSorted(arr4) == false);

    // Test Case 5: Single element array
    std::vector<int> arr5 = {100};
    assert(sol.isSorted(arr5) == true);

    // Test Case 6: Empty array
    std::vector<int> arr6 = {};
    assert(sol.isSorted(arr6) == true);

    std::cout << "Check Sorted C++: All tests passed! 🎉" << std::endl;
    return 0;
}
