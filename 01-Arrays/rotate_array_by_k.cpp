/*
Problem Name: Rotate Array by K
Platform: LeetCode
Difficulty: Medium

Approach 1: Using an auxiliary array of size n. Place elements at their correct new positions (i + k) % n. Then copy back. Space Complexity O(n).
Optimal Approach: Three-step reversal. Reverse the entire array, then reverse the first k elements, and finally reverse the remaining n-k elements. This performs the rotation in-place.

Time Complexity: O(n) worst and average case, since each element is reversed at most twice.
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers / Reversal
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
private:
    void reverse(std::vector<int>& nums, int start, int end) {
        while (start < end) {
            std::swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        k = k % n;
        if (k == 0) return;
        
        // Reverse all elements
        reverse(nums, 0, n - 1);
        // Reverse first k elements
        reverse(nums, 0, k - 1);
        // Reverse remaining n-k elements
        reverse(nums, k, n - 1);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard right rotation
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expected1 = {5, 6, 7, 1, 2, 3, 4};
    sol.rotate(arr1, 3);
    assert(arr1 == expected1);

    // Test Case 2: Rotation by k > size
    std::vector<int> arr2 = {-1, -100, 3, 99};
    std::vector<int> expected2 = {3, 99, -1, -100};
    sol.rotate(arr2, 2);
    assert(arr2 == expected2);

    // Test Case 3: Rotation by k = 0
    std::vector<int> arr3 = {1, 2, 3};
    std::vector<int> expected3 = {1, 2, 3};
    sol.rotate(arr3, 0);
    assert(arr3 == expected3);

    // Test Case 4: Rotation by k = size
    std::vector<int> arr4 = {1, 2, 3};
    std::vector<int> expected4 = {1, 2, 3};
    sol.rotate(arr4, 3);
    assert(arr4 == expected4);

    // Test Case 5: Single element array
    std::vector<int> arr5 = {10};
    std::vector<int> expected5 = {10};
    sol.rotate(arr5, 5);
    assert(arr5 == expected5);

    // Test Case 6: Empty array
    std::vector<int> arr6 = {};
    std::vector<int> expected6 = {};
    sol.rotate(arr6, 3);
    assert(arr6 == expected6);

    std::cout << "Rotate Array by K C++: All tests passed! 🎉" << std::endl;
    return 0;
}
