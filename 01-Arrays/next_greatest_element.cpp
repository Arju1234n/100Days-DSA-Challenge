/*
Problem Name: Next Greatest Element (Replace elements with greatest element on right side)
Platform: GeeksforGeeks / LeetCode (1299)
Difficulty: Easy

Approach: Iterative Right-to-Left Scan
We start from the second-to-last element and move towards the beginning.
We keep track of the maximum element seen so far (initialized to the last element).
At each step, we save the current element, update the current position with the max seen so far, and update the max seen so far.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (modifying the input array in-place)

Pattern: Arrays / Suffix Max / Scan from Right
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<int> nextGreatest(std::vector<int> arr) {
        int n = arr.size();
        if (n == 0) return arr;

        int maxi = arr[n - 1];
        arr[n - 1] = -1;

        for (int i = n - 2; i >= 0; i--) {
            int temp = arr[i];   // original value save
            arr[i] = maxi;       // replace with greatest on right
            maxi = std::max(maxi, temp);
        }

        return arr;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard GFG/LeetCode case
    std::vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    std::vector<int> expected1 = {17, 5, 5, 5, 2, -1};
    assert(sol.nextGreatest(arr1) == expected1);

    // Test Case 2: Single element
    std::vector<int> arr2 = {10};
    std::vector<int> expected2 = {-1};
    assert(sol.nextGreatest(arr2) == expected2);

    // Test Case 3: Elements in strictly increasing order
    std::vector<int> arr3 = {1, 2, 3, 4};
    std::vector<int> expected3 = {4, 4, 4, -1};
    assert(sol.nextGreatest(arr3) == expected3);

    // Test Case 4: Elements in strictly decreasing order
    std::vector<int> arr4 = {4, 3, 2, 1};
    std::vector<int> expected4 = {3, 2, 1, -1};
    assert(sol.nextGreatest(arr4) == expected4);

    std::cout << "Next Greatest Element C++: All tests passed! 🎉" << std::endl;
    return 0;
}
