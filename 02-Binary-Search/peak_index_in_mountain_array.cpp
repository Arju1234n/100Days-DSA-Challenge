/*
Problem Name: Peak Index in a Mountain Array
Platform: LeetCode
Difficulty: Medium

Approach: Binary Search. Since the array is guaranteed to be a mountain array, it increases to a peak element and then decreases.
We can use binary search to find the peak index. At any mid index, if arr[mid] > arr[mid+1], it means we are in the decreasing part of the mountain.
Therefore, the peak could be at mid or to the left of mid. So we set right = mid.
Otherwise, we are in the increasing part of the mountain, meaning the peak must be to the right of mid. So we set left = mid + 1.
The search terminates when left == right, which points to the peak index.

Time Complexity: O(log n) worst and average case, since the search space is halved in each step.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search / Peak Finding
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
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
        return right;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Minimal mountain array
    std::vector<int> arr1 = {0, 1, 0};
    assert(sol.peakIndexInMountainArray(arr1) == 1);

    // Test Case 2: Peak on the left side
    std::vector<int> arr2 = {0, 2, 1, 0};
    assert(sol.peakIndexInMountainArray(arr2) == 1);

    // Test Case 3: Peak on the right side
    std::vector<int> arr3 = {0, 10, 5, 2};
    assert(sol.peakIndexInMountainArray(arr3) == 1);

    // Test Case 4: Larger mountain array
    std::vector<int> arr4 = {3, 4, 5, 1};
    assert(sol.peakIndexInMountainArray(arr4) == 2);

    // Test Case 5: Standard LeetCode example
    std::vector<int> arr5 = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    assert(sol.peakIndexInMountainArray(arr5) == 2);

    std::cout << "Peak Index in Mountain Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
