/*
Problem Name: Binary Search (Recursive)
Platform: LeetCode #704
Difficulty: Easy

Approach: Recursion
  Array must be sorted. At every call, compare target with the mid element:
    • target == arr[mid] → found, return mid
    • target <  arr[mid] → search left  half: [lo, mid-1]
    • target >  arr[mid] → search right half: [mid+1, hi]
  Base Case: lo > hi → target not present, return -1

Time Complexity : O(log N) — search space halves each call
Space Complexity: O(log N) — recursion call stack depth
Pattern: Recursion / Binary Search
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int binarySearch(std::vector<int>& arr, int lo, int hi, int target) {
        // Base Case: search space exhausted
        if (lo > hi)
            return -1;

        int mid = lo + (hi - lo) / 2;  // avoids integer overflow

        if (arr[mid] == target)
            return mid;                             // Found
        else if (target < arr[mid])
            return binarySearch(arr, lo, mid - 1, target);  // Search left
        else
            return binarySearch(arr, mid + 1, hi, target);  // Search right
    }

    int search(std::vector<int>& arr, int target) {
        return binarySearch(arr, 0, (int)arr.size() - 1, target);
    }
};

int main() {
    Solution sol;

    // Test 1: standard sorted array
    std::vector<int> arr1 = {-1, 0, 3, 5, 9, 12};
    assert(sol.search(arr1, 9)  == 4);
    assert(sol.search(arr1, 2)  == -1);
    assert(sol.search(arr1, -1) == 0);
    assert(sol.search(arr1, 12) == 5);

    // Test 2: single element
    std::vector<int> arr2 = {5};
    assert(sol.search(arr2, 5)  == 0);
    assert(sol.search(arr2, 0)  == -1);

    // Test 3: two elements
    std::vector<int> arr3 = {1, 3};
    assert(sol.search(arr3, 1)  == 0);
    assert(sol.search(arr3, 3)  == 1);

    // Print demo
    std::cout << "Binary Search demo on [-1, 0, 3, 5, 9, 12]:\n";
    for (int t : {9, -1, 12, 2, 5}) {
        int idx = sol.search(arr1, t);
        if (idx != -1)
            std::cout << "  target=" << t << " → found at index " << idx << "\n";
        else
            std::cout << "  target=" << t << " → not found\n";
    }

    std::cout << "\nBinary Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
