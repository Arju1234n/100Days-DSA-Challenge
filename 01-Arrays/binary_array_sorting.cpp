/*
Problem Name: Binary Array Sorting
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Two Pass (Counting). Count number of 0s and fill the array.
Time Complexity: O(n) - two passes
Space Complexity: O(1)

Approach 2: Single Pass (Two Pointers/Partitioning). Use two pointers to swap 0s to the front.
Time Complexity: O(n) - single pass
Space Complexity: O(1)

Pattern: Two Pointers / Partitioning
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    void binSort(std::vector<int>& arr) {
        int i = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == 0) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: Mixed array
    std::vector<int> arr1 = {1, 0, 1, 1, 0};
    std::vector<int> expected1 = {0, 0, 1, 1, 1};
    sol.binSort(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Already sorted
    std::vector<int> arr2 = {0, 0, 1, 1};
    std::vector<int> expected2 = {0, 0, 1, 1};
    sol.binSort(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Reverse sorted
    std::vector<int> arr3 = {1, 1, 0, 0};
    std::vector<int> expected3 = {0, 0, 1, 1};
    sol.binSort(arr3);
    assert(arr3 == expected3);

    // Test Case 4: All 0s
    std::vector<int> arr4 = {0, 0, 0};
    std::vector<int> expected4 = {0, 0, 0};
    sol.binSort(arr4);
    assert(arr4 == expected4);

    // Test Case 5: All 1s
    std::vector<int> arr5 = {1, 1, 1};
    std::vector<int> expected5 = {1, 1, 1};
    sol.binSort(arr5);
    assert(arr5 == expected5);

    // Test Case 6: Empty array
    std::vector<int> arr6 = {};
    std::vector<int> expected6 = {};
    sol.binSort(arr6);
    assert(arr6 == expected6);

    std::cout << "Binary Array Sorting C++: All tests passed! 🎉" << std::endl;
    return 0;
}
