/*
Problem Name: Find Minimum and Maximum Element in an Array
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Linear Scan (Naive). Scan elements one by one and keep track of min and max.
Comparisons: 2 * (n - 1)
Time Complexity: O(n)
Space Complexity: O(1)

Approach 2: Pairwise Comparisons (Optimal). Compare elements in pairs to reduce total comparisons.
Comparisons: ~1.5 * n
Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Pairwise Comparison
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

class Solution {
public:
    std::pair<int, int> getMinMax(const std::vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return {-1, -1}; // Fallback for empty array

        int mini, maxi;
        int i;

        // If array has odd size, initialize both min and max to the first element
        if (n % 2 != 0) {
            mini = arr[0];
            maxi = arr[0];
            i = 1;
        } 
        // If array has even size, initialize min and max by comparing first two elements
        else {
            if (arr[0] < arr[1]) {
                mini = arr[0];
                maxi = arr[1];
            } else {
                mini = arr[1];
                maxi = arr[0];
            }
            i = 2;
        }

        // Process elements in pairs
        while (i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                if (arr[i] < mini) mini = arr[i];
                if (arr[i + 1] > maxi) maxi = arr[i + 1];
            } else {
                if (arr[i + 1] < mini) mini = arr[i + 1];
                if (arr[i] > maxi) maxi = arr[i];
            }
            i += 2;
        }

        return {mini, maxi};
    }
};

int main() {
    Solution sol;

    // Test Case 1: Odd size array
    std::vector<int> arr1 = {3, 2, 1, 56, 10000, 167};
    std::pair<int, int> res1 = sol.getMinMax(arr1);
    assert(res1.first == 1 && res1.second == 10000);

    // Test Case 2: Even size array
    std::vector<int> arr2 = {1, 345, 234, 21, 56789};
    std::pair<int, int> res2 = sol.getMinMax(arr2);
    assert(res2.first == 1 && res2.second == 56789);

    // Test Case 3: Single element array
    std::vector<int> arr3 = {42};
    std::pair<int, int> res3 = sol.getMinMax(arr3);
    assert(res3.first == 42 && res3.second == 42);

    // Test Case 4: Duplicate elements
    std::vector<int> arr4 = {5, 5, 5, 5};
    std::pair<int, int> res4 = sol.getMinMax(arr4);
    assert(res4.first == 5 && res4.second == 5);

    std::cout << "Find Min Max C++: All tests passed! 🎉" << std::endl;
    return 0;
}
