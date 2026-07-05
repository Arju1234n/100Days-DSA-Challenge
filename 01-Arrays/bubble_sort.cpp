/*
Problem Name: Bubble Sort
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Repeatedly step through the list, compare adjacent elements, and swap them if they are in the wrong order.
Optimal Approach: Optimized Bubble Sort which includes a swapped flag to break early if the array is already sorted in any pass.

Time Complexity: O(n^2) worst and average case, O(n) best case (when already sorted)
Space Complexity: O(1) auxiliary space

Pattern: Sorting
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            // If no two elements were swapped by inner loop, then break
            if (!swapped) {
                break;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: General unsorted array
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> expected1 = {11, 12, 22, 25, 34, 64, 90};
    sol.bubbleSort(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Already sorted array
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    sol.bubbleSort(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Reverse sorted array
    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    std::vector<int> expected3 = {1, 2, 3, 4, 5};
    sol.bubbleSort(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Array with duplicates
    std::vector<int> arr4 = {3, 1, 2, 3, 1, 2};
    std::vector<int> expected4 = {1, 1, 2, 2, 3, 3};
    sol.bubbleSort(arr4);
    assert(arr4 == expected4);

    // Test Case 5: Empty array
    std::vector<int> arr5 = {};
    std::vector<int> expected5 = {};
    sol.bubbleSort(arr5);
    assert(arr5 == expected5);

    // Test Case 6: Single element array
    std::vector<int> arr6 = {42};
    std::vector<int> expected6 = {42};
    sol.bubbleSort(arr6);
    assert(arr6 == expected6);

    std::cout << "Bubble Sort C++: All tests passed! 🎉" << std::endl;
    return 0;
}
