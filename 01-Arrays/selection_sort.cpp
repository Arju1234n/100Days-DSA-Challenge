/*
Problem Name: Selection Sort
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Iterative sorting. It repeatedly finds the minimum element from the unsorted part and puts it at the beginning.
Optimal Approach: Standard Selection Sort. It performs minimum number of writes/swaps O(n), which is useful when memory write is a costly operation.

Time Complexity: O(n^2) worst, average, and best case
Space Complexity: O(1) auxiliary space

Pattern: Sorting
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Swap the found minimum element with the first element
            if (min_idx != i) {
                std::swap(arr[i], arr[min_idx]);
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: General unsorted array
    std::vector<int> arr1 = {64, 25, 12, 22, 11};
    std::vector<int> expected1 = {11, 12, 22, 25, 64};
    sol.selectionSort(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Already sorted array
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    sol.selectionSort(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Reverse sorted array
    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    std::vector<int> expected3 = {1, 2, 3, 4, 5};
    sol.selectionSort(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Array with duplicates
    std::vector<int> arr4 = {5, 1, 2, 5, 1, 2};
    std::vector<int> expected4 = {1, 1, 2, 2, 5, 5};
    sol.selectionSort(arr4);
    assert(arr4 == expected4);

    // Test Case 5: Empty array
    std::vector<int> arr5 = {};
    std::vector<int> expected5 = {};
    sol.selectionSort(arr5);
    assert(arr5 == expected5);

    // Test Case 6: Single element array
    std::vector<int> arr6 = {7};
    std::vector<int> expected6 = {7};
    sol.selectionSort(arr6);
    assert(arr6 == expected6);

    std::cout << "Selection Sort C++: All tests passed! 🎉" << std::endl;
    return 0;
}
