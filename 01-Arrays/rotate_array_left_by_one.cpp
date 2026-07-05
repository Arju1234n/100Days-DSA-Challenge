/*
Problem Name: Rotate Array Left by One
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Store the first element of the array in a temporary variable. Shift all other elements one position to the left. Finally, place the first element (from the temporary variable) at the last index of the array.

Time Complexity: O(n) worst and average case, since we traverse the array of size n once.
Space Complexity: O(1) auxiliary space

Pattern: Array Manipulation
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    void rotateLeftByOne(std::vector<int>& arr) {
        if (arr.empty()) return;
        int n = arr.size();
        int temp = arr[0];
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> expected1 = {2, 3, 4, 5, 1};
    sol.rotateLeftByOne(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Single element array
    std::vector<int> arr2 = {42};
    std::vector<int> expected2 = {42};
    sol.rotateLeftByOne(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Empty array
    std::vector<int> arr3 = {};
    std::vector<int> expected3 = {};
    sol.rotateLeftByOne(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Array with duplicates
    std::vector<int> arr4 = {1, 2, 1, 2};
    std::vector<int> expected4 = {2, 1, 2, 1};
    sol.rotateLeftByOne(arr4);
    assert(arr4 == expected4);

    std::cout << "Rotate Array Left by One C++: All tests passed! 🎉" << std::endl;
    return 0;
}
