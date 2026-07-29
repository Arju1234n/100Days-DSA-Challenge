/*
Problem Name: Rearrange an Array
Platform: GeeksforGeeks
Difficulty: Medium

Approach 1: Using auxiliary space.
We create a temporary array 'temp' of size n. For each index i, we set temp[i] = arr[arr[i]].
Finally, we copy the elements of 'temp' back to 'arr'.

Time Complexity: O(n)
Space Complexity: O(n)

Pattern: Arrays
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
  public:
    void arrange(std::vector<int>& arr) {
        int n = arr.size();

        std::vector<int> temp(n);

        for(int i = 0; i < n; i++) {
            temp[i] = arr[arr[i]];
        }

        arr = temp;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> arr1 = {1, 0};
    std::vector<int> expected1 = {0, 1};
    sol.arrange(arr1);
    assert(arr1 == expected1);

    // Test Case 2
    std::vector<int> arr2 = {4, 0, 2, 1, 3};
    std::vector<int> expected2 = {3, 4, 2, 0, 1};
    sol.arrange(arr2);
    assert(arr2 == expected2);

    std::cout << "Rearrange an Array C++: All tests passed! 🎉" << std::endl;
    return 0;
}
