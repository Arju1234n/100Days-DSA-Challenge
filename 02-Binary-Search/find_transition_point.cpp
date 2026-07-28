/*
Problem Name: Find Transition Point
Platform: GeeksforGeeks
Difficulty: Easy

Approach: Binary Search. Since the array is sorted and contains only 0s and 1s, we want to find the first occurrence of 1.
- We maintain a variable `ans` initialized to -1.
- We run binary search with the condition `low <= high` (which correctly handles all elements, including boundaries).
- If `arr[mid] == 0`, it means the transition point lies to the right, so we set `low = mid + 1`.
- If `arr[mid] == 1`, this could be a potential transition point, so we set `ans = mid` and search the left side by setting `high = mid - 1`.

Time Complexity: O(log n)
Space Complexity: O(1)

Pattern: Binary Search / First Occurrence
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int transitionPoint(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == 0) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard transition
    vector<int> arr1 = {0, 0, 0, 1, 1};
    assert(sol.transitionPoint(arr1) == 3);

    // Test Case 2: Transition at first element
    vector<int> arr2 = {1, 1, 1};
    assert(sol.transitionPoint(arr2) == 0);

    // Test Case 3: Transition at last element
    vector<int> arr3 = {0, 0, 1};
    assert(sol.transitionPoint(arr3) == 2);

    // Test Case 4: No transition (all 0s)
    vector<int> arr4 = {0, 0, 0};
    assert(sol.transitionPoint(arr4) == -1);

    cout << "Find Transition Point C++: All tests passed! 🎉" << endl;
    return 0;
}
