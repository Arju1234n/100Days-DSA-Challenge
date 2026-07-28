/*
Problem Name: Union of Two Sorted Arrays
Platform: GeeksForGeeks
Difficulty: Easy

Approach: Two-pointer technique to traverse both sorted arrays. Compare elements and add the smaller one to the union array if it is not already present (checking `ans.back()`). If elements are equal, add once and increment both pointers.

Time Complexity: O(n + m) where n and m are the sizes of the two arrays.
Space Complexity: O(1) auxiliary space (excluding the output array).

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                if (ans.empty() || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            } else {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        while (i < a.size()) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        while (j < b.size()) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> b1 = {1, 2, 3, 6, 7};
    vector<int> expected1 = {1, 2, 3, 4, 5, 6, 7};
    assert(sol.findUnion(a1, b1) == expected1);

    // Test Case 2: Duplicates in input
    vector<int> a2 = {2, 2, 3, 4, 5};
    vector<int> b2 = {1, 1, 2, 5, 6};
    vector<int> expected2 = {1, 2, 3, 4, 5, 6};
    assert(sol.findUnion(a2, b2) == expected2);

    // Test Case 3: One array empty
    vector<int> a3 = {1, 2, 3};
    vector<int> b3 = {};
    vector<int> expected3 = {1, 2, 3};
    assert(sol.findUnion(a3, b3) == expected3);

    cout << "Union of Two Sorted Arrays C++: All tests passed! 🎉" << endl;
    return 0;
}
