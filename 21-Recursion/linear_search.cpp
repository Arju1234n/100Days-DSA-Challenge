/*
Problem Name: Linear Search (Recursive)
Platform: General
Difficulty: Easy

Approach: Recursion
  Scan the array one element at a time from left to right.
  Base Cases:
    1. index == arr.size() → target not found, return -1
    2. arr[index] == target → found, return index
  Recursive Case: search(index + 1, ...)

Time Complexity : O(N) — at most N comparisons
Space Complexity: O(N) — recursion call stack depth
Pattern: Recursion / Searching
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    // Returns index of target, or -1 if not found
    int linearSearch(int index, std::vector<int>& arr, int target) {
        // Base Case 1: exhausted the array
        if (index == (int)arr.size())
            return -1;

        // Base Case 2: element found
        if (arr[index] == target)
            return index;

        // Recursive Case: check next index
        return linearSearch(index + 1, arr, target);
    }

    int search(std::vector<int>& arr, int target) {
        return linearSearch(0, arr, target);
    }
};

int main() {
    Solution sol;

    // Test 1: target present
    std::vector<int> arr1 = {4, 2, 7, 1, 9, 3};
    assert(sol.search(arr1, 7) == 2);
    assert(sol.search(arr1, 4) == 0);
    assert(sol.search(arr1, 3) == 5);

    // Test 2: target absent
    assert(sol.search(arr1, 10) == -1);

    // Test 3: single element
    std::vector<int> arr2 = {42};
    assert(sol.search(arr2, 42) == 0);
    assert(sol.search(arr2, 99) == -1);

    // Print demo
    std::cout << "Linear Search demo on [4, 2, 7, 1, 9, 3]:\n";
    for (int t : {7, 4, 3, 10}) {
        int idx = sol.search(arr1, t);
        if (idx != -1)
            std::cout << "  target=" << t << " → found at index " << idx << "\n";
        else
            std::cout << "  target=" << t << " → not found\n";
    }

    std::cout << "\nLinear Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
