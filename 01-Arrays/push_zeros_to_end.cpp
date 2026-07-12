/*
Problem Name: Push Zeros to End
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Two Pointers. Maintain a 'left' pointer representing the position where the next non-zero element should go.
Traverse the array with a 'right' pointer. When arr[right] is non-zero, swap it with arr[left] and increment left.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers / Arrays
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void pushZerosToEnd(std::vector<int>& arr) {
        int left = 0;
        for (size_t right = 0; right < arr.size(); right++) {
            if (arr[right] != 0) {
                std::swap(arr[left], arr[right]);
                left++;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> arr1 = {1, 2, 0, 4, 3, 0, 5, 0};
    std::vector<int> expected1 = {1, 2, 4, 3, 5, 0, 0, 0};
    sol.pushZerosToEnd(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Only zeros
    std::vector<int> arr2 = {0, 0, 0};
    std::vector<int> expected2 = {0, 0, 0};
    sol.pushZerosToEnd(arr2);
    assert(arr2 == expected2);

    // Test Case 3: No zeros
    std::vector<int> arr3 = {1, 2, 3};
    std::vector<int> expected3 = {1, 2, 3};
    sol.pushZerosToEnd(arr3);
    assert(arr3 == expected3);

    std::cout << "Push Zeros to End C++: All tests passed! 🎉" << std::endl;
    return 0;
}
