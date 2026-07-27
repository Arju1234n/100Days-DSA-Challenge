/*
Problem Name: Sort Colors (Sort 0s, 1s, and 2s)
Platform: GeeksforGeeks / LeetCode
Difficulty: Medium

Approach: Dutch National Flag Algorithm (Three-Way Partitioning)
We maintain three pointers: low, mid, and high.
- Elements before 'low' are 0.
- Elements between 'low' and 'mid-1' are 1.
- Elements after 'high' are 2.
- The region 'mid' to 'high' is unexplored.
We iterate and partition the array in a single pass.

Time Complexity: O(n) - Single pass
Space Complexity: O(1) - Auxiliary space

Pattern: Two Pointers / Partitioning / Dutch National Flag
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    // GeeksforGeeks style signature
    void sort012(std::vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                std::swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else {
                std::swap(arr[mid], arr[high]);
                high--;
            }
        }
    }

    // LeetCode style alias
    void sortColors(std::vector<int>& nums) {
        sort012(nums);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> arr1 = {2, 0, 2, 1, 1, 0};
    std::vector<int> expected1 = {0, 0, 1, 1, 2, 2};
    sol.sort012(arr1);
    assert(arr1 == expected1);

    // Test Case 2: Already sorted
    std::vector<int> arr2 = {0, 0, 1, 1, 2, 2};
    std::vector<int> expected2 = {0, 0, 1, 1, 2, 2};
    sol.sort012(arr2);
    assert(arr2 == expected2);

    // Test Case 3: Reverse sorted
    std::vector<int> arr3 = {2, 2, 1, 1, 0, 0};
    std::vector<int> expected3 = {0, 0, 1, 1, 2, 2};
    sol.sort012(arr3);
    assert(arr3 == expected3);

    // Test Case 4: Single element 0
    std::vector<int> arr4 = {0};
    std::vector<int> expected4 = {0};
    sol.sort012(arr4);
    assert(arr4 == expected4);

    // Test Case 5: Single element 1
    std::vector<int> arr5 = {1};
    std::vector<int> expected5 = {1};
    sol.sort012(arr5);
    assert(arr5 == expected5);

    // Test Case 6: Single element 2
    std::vector<int> arr6 = {2};
    std::vector<int> expected6 = {2};
    sol.sort012(arr6);
    assert(arr6 == expected6);

    // Test Case 7: All 0s
    std::vector<int> arr7 = {0, 0, 0};
    std::vector<int> expected7 = {0, 0, 0};
    sol.sort012(arr7);
    assert(arr7 == expected7);

    // Test Case 8: All 1s
    std::vector<int> arr8 = {1, 1, 1};
    std::vector<int> expected8 = {1, 1, 1};
    sol.sort012(arr8);
    assert(arr8 == expected8);

    // Test Case 9: All 2s
    std::vector<int> arr9 = {2, 2, 2};
    std::vector<int> expected9 = {2, 2, 2};
    sol.sort012(arr9);
    assert(arr9 == expected9);

    // Test Case 10: Empty array
    std::vector<int> arr10 = {};
    std::vector<int> expected10 = {};
    sol.sort012(arr10);
    assert(arr10 == expected10);

    std::cout << "Sort Colors (Sort 0s, 1s, and 2s) C++: All tests passed! 🎉" << std::endl;
    return 0;
}
