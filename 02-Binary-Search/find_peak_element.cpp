/*
Problem Name: Find Peak Element
Platform: LeetCode / GeeksforGeeks
Difficulty: Medium

Approach: Binary Search. An element is a peak if it is greater than or equal to its neighbors.
In a peak-finding problem, we can examine the middle element `mid` and its neighbor `mid + 1`.
- If `arr[mid] > arr[mid + 1]`, it means the slope is decreasing, so there must be a peak on the left half (including `mid` itself). Thus, we set `right = mid`.
- If `arr[mid] <= arr[mid + 1]`, it means the slope is increasing, so there must be a peak on the right half (excluding `mid`). Thus, we set `left = mid + 1`.
This logic works because the boundaries are effectively $-\infty$ at the ends, guaranteeing that a peak always exists.

Time Complexity: O(log n) worst and average case, since the search space is halved in each step.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search on Unsorted Array / Peak Finding
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int peakElement(std::vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Peak in the middle
    std::vector<int> arr1 = {1, 2, 3, 1};
    int res1 = sol.peakElement(arr1);
    // 3 is the peak at index 2
    assert(res1 == 2);

    // Test Case 2: Multiple peaks, return any
    std::vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    int res2 = sol.peakElement(arr2);
    // Peaks are at index 1 (value 2) or index 5 (value 6).
    // Our binary search algorithm will find index 5.
    assert(res2 == 1 || res2 == 5);

    // Test Case 3: Peak at the end (strictly increasing)
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int res3 = sol.peakElement(arr3);
    assert(res3 == 4);

    // Test Case 4: Peak at the beginning (strictly decreasing)
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    int res4 = sol.peakElement(arr4);
    assert(res4 == 0);

    // Test Case 5: Single element
    std::vector<int> arr5 = {10};
    int res5 = sol.peakElement(arr5);
    assert(res5 == 0);

    std::cout << "Find Peak Element C++: All tests passed! 🎉" << std::endl;
    return 0;
}
