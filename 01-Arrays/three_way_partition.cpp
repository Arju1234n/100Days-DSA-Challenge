/*
Problem Name: Three Way Partitioning
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Dutch National Flag algorithm. Maintain three pointers: low, mid, and high.
- If arr[mid] < a: swap with arr[low], increment low and mid.
- If a <= arr[mid] <= b: increment mid.
- If arr[mid] > b: swap with arr[high], decrement high.

Time Complexity: O(n) where n is the number of elements in the array.
Space Complexity: O(1) auxiliary space (in-place partitioning).

Pattern: Three-way Partition / Dutch National Flag / Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] < a) {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            } else if (arr[mid] <= b) {
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

// Helper function to verify partitioning
bool isPartitioned(const vector<int>& arr, int a, int b) {
    int state = 0; // 0: < a, 1: between a and b, 2: > b
    for (int x : arr) {
        if (x < a) {
            if (state > 0) return false;
        } else if (x <= b) {
            if (state > 1) return false;
            state = 1;
        } else {
            state = 2;
        }
    }
    return true;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 3, 4};
    sol.threeWayPartition(arr1, 1, 2);
    assert(isPartitioned(arr1, 1, 2));

    // Test Case 2
    vector<int> arr2 = {2, 1, 2, 4, 3};
    sol.threeWayPartition(arr2, 3, 5);
    assert(isPartitioned(arr2, 3, 5));

    // Test Case 3
    vector<int> arr3 = {9, 4, 7, 2, 1, 8, 5};
    sol.threeWayPartition(arr3, 4, 7);
    assert(isPartitioned(arr3, 4, 7));

    cout << "Three Way Partitioning C++: All tests passed! 🎉" << endl;
    return 0;
}
