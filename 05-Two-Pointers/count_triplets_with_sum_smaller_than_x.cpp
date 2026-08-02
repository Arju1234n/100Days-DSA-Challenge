/*
Problem Name: Count Triplets with Sum Smaller than X
Platform: GeeksforGeeks
Difficulty: Medium

Approach: Sort the array. Fix the first element using a loop, then use two pointers (left and right).
If arr[i] + arr[left] + arr[right] < sum, then for all indices between left and right, the sum with arr[i] and arr[left] will also be < sum.
So add (right - left) to count and increment left. Otherwise, decrement right.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding space for sorting)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int countTriplets(int sum, std::vector<int>& arr) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());
        
        int count = 0;
        
        // Fix first element
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = arr[i] + arr[left] + arr[right];
                
                // Valid triplets
                if (total < sum) {
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> arr1 = {-2, 0, 1, 3};
    int sum1 = 2;
    assert(sol.countTriplets(sum1, arr1) == 2);

    // Test Case 2
    std::vector<int> arr2 = {5, 1, 3, 4, 7};
    int sum2 = 12;
    assert(sol.countTriplets(sum2, arr2) == 4);

    std::cout << "Count Triplets with Sum Smaller than X C++: All tests passed! 🎉" << std::endl;
    return 0;
}
