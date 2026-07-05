/*
Problem Name: Number of Occurrence
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Linear Scan. Traverse the array from left to right and count occurrences of the target. Time Complexity: O(n).
Optimal Approach: Binary Search. Use binary search to find the first (leftmost) occurrence and the last (rightmost) occurrence of the target. If target is present, the count is given by (last_occurrence_index - first_occurrence_index + 1). If not present, return 0.

Time Complexity: O(log n) worst and average case, as we run binary search twice.
Space Complexity: O(1) auxiliary space

Pattern: Binary Search / Left-Right Bound
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
private:
    int findBound(const std::vector<int>& arr, int target, bool isFirst) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int bound = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                bound = mid;
                if (isFirst) {
                    high = mid - 1; // Search left for first occurrence
                } else {
                    low = mid + 1;  // Search right for last occurrence
                }
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return bound;
    }

public:
    int countOccurrences(const std::vector<int>& arr, int target) {
        int first = findBound(arr, target, true);
        if (first == -1) {
            return 0;
        }
        int last = findBound(arr, target, false);
        return (last - first + 1);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Target present multiple times
    std::vector<int> arr1 = {1, 1, 2, 2, 2, 2, 3};
    assert(sol.countOccurrences(arr1, 2) == 4);

    // Test Case 2: Target present once
    std::vector<int> arr2 = {1, 1, 2, 2, 2, 2, 3};
    assert(sol.countOccurrences(arr2, 3) == 1);

    // Test Case 3: Target not present
    std::vector<int> arr3 = {1, 1, 2, 2, 2, 2, 3};
    assert(sol.countOccurrences(arr3, 4) == 0);

    // Test Case 4: Empty array
    std::vector<int> arr4 = {};
    assert(sol.countOccurrences(arr4, 10) == 0);

    // Test Case 5: Single element - target present
    std::vector<int> arr5 = {5};
    assert(sol.countOccurrences(arr5, 5) == 1);

    // Test Case 6: Single element - target not present
    std::vector<int> arr6 = {5};
    assert(sol.countOccurrences(arr6, 2) == 0);

    // Test Case 7: All elements are target
    std::vector<int> arr7 = {8, 8, 8, 8, 8};
    assert(sol.countOccurrences(arr7, 8) == 5);

    std::cout << "Number of Occurrence C++: All tests passed! 🎉" << std::endl;
    return 0;
}
