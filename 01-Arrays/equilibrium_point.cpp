/*
Problem Name: Equilibrium Point (Equilibrium Index of an Array)
Platform: GeeksforGeeks / LeetCode (1991 / 724)
Difficulty: Easy

Approach: Prefix Sum concept.
1. First, calculate the total sum of all elements in the array.
2. Maintain a `leftsum` variable initialized to 0.
3. Traverse the array, and at each index `i`, check if `leftsum` is equal to `rightsum`.
   - `rightsum` can be computed in O(1) as `total_sum - leftsum - arr[i]`.
   - If they are equal, `i` is the equilibrium point.
   - Otherwise, add `arr[i]` to `leftsum` and continue.
4. If no such index is found, return -1.

Time Complexity: O(n) - Two linear passes
Space Complexity: O(1) - Auxiliary space

Pattern: Arrays / Prefix Sum
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

class Solution {
public:
    int findEquilibrium(vector<int> &arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); i++) {
            total += arr[i];
        }
        
        int leftsum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int rightsum = total - leftsum - arr[i];
            if (leftsum == rightsum)
                return i;
            leftsum += arr[i];
        }
        
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> arr1 = {1, 3, 5, 2, 2};
    assert(sol.findEquilibrium(arr1) == 2); // index 2 (val 5) has leftsum=4, rightsum=4

    // Test Case 2: No equilibrium point
    vector<int> arr2 = {1, 2, 3};
    assert(sol.findEquilibrium(arr2) == -1);

    // Test Case 3: Equilibrium at the first element
    vector<int> arr3 = {0, 1, -1};
    assert(sol.findEquilibrium(arr3) == 0); // index 0 has leftsum=0, rightsum=0

    // Test Case 4: Single element
    vector<int> arr4 = {10};
    assert(sol.findEquilibrium(arr4) == 0); // index 0 has leftsum=0, rightsum=0

    cout << "Equilibrium Point C++: All tests passed! 🎉" << endl;
    return 0;
}
