/*
Problem Name: Linear Search
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Iterate through the array and compare each element with the target. If found, return its index. If not found after checking all elements, return -1.

Time Complexity: O(n) worst and average case, O(1) best case (when element is at the first index)
Space Complexity: O(1) auxiliary space

Pattern: Linear Scan
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int linearSearch(const std::vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Element is in the middle
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    assert(sol.linearSearch(arr1, 5) == 2);

    // Test Case 2: Element is at the beginning
    std::vector<int> arr2 = {4, 8, 15, 16, 23, 42};
    assert(sol.linearSearch(arr2, 4) == 0);

    // Test Case 3: Element is at the end
    std::vector<int> arr3 = {10, 20, 30, 40};
    assert(sol.linearSearch(arr3, 40) == 3);

    // Test Case 4: Element is not present
    std::vector<int> arr4 = {1, 2, 3};
    assert(sol.linearSearch(arr4, 5) == -1);

    // Test Case 5: Empty array
    std::vector<int> arr5 = {};
    assert(sol.linearSearch(arr5, 10) == -1);

    // Test Case 6: Multiple occurrences (should return first occurrence)
    std::vector<int> arr6 = {2, 4, 6, 4, 8};
    assert(sol.linearSearch(arr6, 4) == 1);

    std::cout << "Linear Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
