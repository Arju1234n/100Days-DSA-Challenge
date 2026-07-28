/*
Problem Name: Minimum Subsets with Consecutive Numbers
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Sort the array. Traverse the sorted array and count the number of elements that are not consecutive to their predecessor (i.e. arr[i] != arr[i-1] + 1). Each such element marks the beginning of a new subset of consecutive numbers.

Time Complexity: O(n log n) due to sorting, where n is the number of elements.
Space Complexity: O(1) auxiliary space (or O(n) depending on the sorting implementation).

Pattern: Sorting
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubsets(vector<int> &arr) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int count = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i-1] + 1)
                count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard consecutive groups
    vector<int> arr1 = {100, 56, 52, 51, 55, 53};
    // Sorted: 51, 52, 53, 55, 56, 100
    // Consecutive groups: {51, 52, 53}, {55, 56}, {100} -> 3 subsets
    assert(sol.minSubsets(arr1) == 3);

    // Test Case 2: Already sorted and consecutive
    vector<int> arr2 = {1, 2, 3, 4, 5};
    assert(sol.minSubsets(arr2) == 1);

    // Test Case 3: No consecutive numbers
    vector<int> arr3 = {2, 4, 6, 8};
    assert(sol.minSubsets(arr3) == 4);

    cout << "Minimum Subsets with Consecutive Numbers C++: All tests passed! 🎉" << endl;
    return 0;
}
