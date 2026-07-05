/*
Problem Name: Insertion Sort
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Iterative sorting. It builds the final sorted array one item at a time by placing each new element in its correct position relative to the already sorted part.
Optimal Approach: Standard Insertion Sort since it runs in O(n) best-case time for already sorted data and performs in-place sorting.

Time Complexity: O(n^2) worst and average case, O(n) best case (when already sorted)
Space Complexity: O(1) auxiliary space

Pattern: Sorting
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            // Move elements of arr[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: General unsorted array
    std::vector<int> arr1 = {12, 11, 13, 5, 6};
    std::vector<int> expected1 = {5, 6, 11, 12, 13};
    sol.insertionSort(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Already sorted array
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    sol.insertionSort(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Reverse sorted array
    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    std::vector<int> expected3 = {1, 2, 3, 4, 5};
    sol.insertionSort(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Array with duplicates
    std::vector<int> arr4 = {4, 2, 2, 8, 3, 3, 1};
    std::vector<int> expected4 = {1, 2, 2, 3, 3, 4, 8};
    sol.insertionSort(arr4);
    assert(arr4 == expected4);

    // Test Case 5: Empty array
    std::vector<int> arr5 = {};
    std::vector<int> expected5 = {};
    sol.insertionSort(arr5);
    assert(arr5 == expected5);

    // Test Case 6: Single element array
    std::vector<int> arr6 = {100};
    std::vector<int> expected6 = {100};
    sol.insertionSort(arr6);
    assert(arr6 == expected6);

    std::cout << "Insertion Sort C++: All tests passed! 🎉" << std::endl;
    return 0;
}
