/*
Problem Name: Find Pair with Given Difference
Platform: GeeksforGeeks
Difficulty: Easy

Approach 1: Brute Force checking all pairs. Time: O(n^2), Space: O(1).
Approach 2: Hashing (using a hash set to store elements and check if complement exists). Time: O(n), Space: O(n).
Optimal Approach: Sort and Two Pointers. Sort the array, then initialize two pointers `i = 0` and `j = 1`. In each step, if `arr[j] - arr[i] == x` and `i != j`, return true. If the difference is less than `x`, increment `j`. Otherwise, increment `i`. If `i == j`, increment `j` to avoid using the same element. Time: O(n log n) due to sorting, Space: O(1).

Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring sorting recursion stack)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

class Solution {
public:
    bool findPair(std::vector<int>& arr, int x) {
        int n = arr.size();
        if (n < 2) {
            return false;
        }
        
        // Sort the array first to use two pointers
        std::sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = 1;
        
        // Use the absolute value of the target difference
        x = std::abs(x);
        
        while (i < n && j < n) {
            if (i != j && arr[j] - arr[i] == x) {
                return true;
            } else if (arr[j] - arr[i] < x) {
                j++;
            } else {
                i++;
            }
            
            // Ensure pointers don't point to the same index
            if (i == j) {
                j++;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case where pair exists
    std::vector<int> arr1 = {5, 20, 3, 2, 5, 80};
    assert(sol.findPair(arr1, 78) == true); // 80 - 2 = 78
    
    // Test Case 2: Case where pair does not exist
    std::vector<int> arr2 = {90, 70, 20, 80, 50};
    assert(sol.findPair(arr2, 45) == false);
    
    // Test Case 3: Target difference is 0 and duplicate exists
    std::vector<int> arr3 = {1, 1, 2, 3, 4};
    assert(sol.findPair(arr3, 0) == true); // 1 - 1 = 0 (different indices)
    
    // Test Case 4: Target difference is 0 but no duplicate exists
    std::vector<int> arr4 = {1, 2, 3, 4};
    assert(sol.findPair(arr4, 0) == false); // Cannot pair an element with itself

    std::cout << "Pair With Difference C++: All tests passed! 🎉" << std::endl;
    return 0;
}
