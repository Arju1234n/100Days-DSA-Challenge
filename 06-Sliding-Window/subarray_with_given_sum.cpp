/*
Problem Name: Subarray with Given Sum
Platform: GeeksforGeeks
Difficulty: Medium

Approach: Sliding Window (Two Pointers)
We maintain a running sum of elements in the current window [start, end].
If the sum exceeds the target, we shrink the window from the left by incrementing 'start' and subtracting arr[start] from the sum.
If the sum equals the target, we return the 1-based start and end indices.
If the loop completes and no subarray matches the target, we return {-1}.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space

Pattern: Sliding Window / Two Pointers / Variable Size Window
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> subarraySum(std::vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int sum = 0;

        for(int end = 0; end < n; end++) {
            sum += arr[end];

            while(sum > target && start <= end) {
                sum -= arr[start];
                start++;
            }

            if(sum == target) {
                return {start + 1, end + 1};
            }
        }

        return {-1};
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    std::vector<int> arr1 = {1, 2, 3, 7, 5};
    int target1 = 12;
    std::vector<int> expected1 = {2, 4}; // 2 + 3 + 7 = 12
    assert(sol.subarraySum(arr1, target1) == expected1);

    // Test Case 2: Subarray at the beginning
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target2 = 15;
    std::vector<int> expected2 = {1, 5}; // 1 + 2 + 3 + 4 + 5 = 15
    assert(sol.subarraySum(arr2, target2) == expected2);

    // Test Case 3: Subarray not found
    std::vector<int> arr3 = {7, 2, 1};
    int target3 = 6;
    std::vector<int> expected3 = {-1};
    assert(sol.subarraySum(arr3, target3) == expected3);

    // Test Case 4: Single element matching target
    std::vector<int> arr4 = {5};
    int target4 = 5;
    std::vector<int> expected4 = {1, 1};
    assert(sol.subarraySum(arr4, target4) == expected4);

    std::cout << "Subarray with Given Sum C++: All tests passed! 🎉" << std::endl;
    return 0;
}
