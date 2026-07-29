/*
Problem Name: Pythagorean Triplet
Platform: GeeksforGeeks
Difficulty: Medium

Approach 1: Using sorting and two-pointer technique.
1. Square all elements in the array.
2. Sort the squared array in ascending order.
3. Fix the largest element (c^2) from the end of the array.
4. Use two pointers (left and right) to find a pair such that a^2 + b^2 = c^2.

Time Complexity: O(n^2)
Space Complexity: O(n) (to store squared values in a temp array)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
  public:
    bool pythagoreanTriplet(std::vector<int>& arr) {
        
        int n = arr.size();
        
        std::vector<long long> temp(n);
        
        // Store squares
        for(int i = 0; i < n; i++) {
            temp[i] = 1LL * arr[i] * arr[i];
        }
        
        std::sort(temp.begin(), temp.end());
        
        // Fix c²
        for(int i = n - 1; i >= 2; i--) {
            
            int left = 0;
            int right = i - 1;
            
            while(left < right) {
                
                long long sum = temp[left] + temp[right];
                
                if(sum == temp[i]) {
                    return true;
                }
                
                else if(sum < temp[i]) {
                    left++;
                }
                
                else {
                    right--;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Triplet exists (3, 4, 5) -> 9 + 16 = 25
    std::vector<int> arr1 = {3, 1, 4, 6, 5};
    assert(sol.pythagoreanTriplet(arr1) == true);

    // Test Case 2: Triplet does not exist
    std::vector<int> arr2 = {10, 4, 6, 12, 5};
    assert(sol.pythagoreanTriplet(arr2) == false);

    // Test Case 3: Another triplet (5, 12, 13)
    std::vector<int> arr3 = {13, 5, 8, 12};
    assert(sol.pythagoreanTriplet(arr3) == true);

    std::cout << "Pythagorean Triplet C++: All tests passed! 🎉" << std::endl;
    return 0;
}
