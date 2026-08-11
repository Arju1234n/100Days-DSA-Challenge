/*
Problem Name: Kth Smallest Element
Platform: GeeksForGeeks
Difficulty: Medium

Approach 1: Sorting the array in ascending order and returning the element at index (k - 1).

Time Complexity: O(n log n) due to std::sort.
Space Complexity: O(1) auxiliary space (or O(log n) for sorting recursion stack).

Pattern: Sorting / Selection
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int kthSmallest(std::vector<int> &arr, int k) {
        std::sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard array
    std::vector<int> arr1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    assert(sol.kthSmallest(arr1, k1) == 7);

    // Test Case 2: Array with duplicate elements
    std::vector<int> arr2 = {7, 10, 4, 20, 15};
    int k2 = 4;
    assert(sol.kthSmallest(arr2, k2) == 15);

    // Test Case 3: Smallest element (k = 1)
    std::vector<int> arr3 = {5, 2, 8, 1, 9};
    int k3 = 1;
    assert(sol.kthSmallest(arr3, k3) == 1);

    // Test Case 4: Largest element (k = N)
    std::vector<int> arr4 = {12, 3, 5, 7, 19};
    int k4 = 5;
    assert(sol.kthSmallest(arr4, k4) == 19);

    std::cout << "Kth Smallest Element C++: All tests passed! 🎉" << std::endl;
    return 0;
}
