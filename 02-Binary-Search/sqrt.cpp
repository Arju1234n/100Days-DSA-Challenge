/*
Problem Name: Square Root of an Integer
Platform: LeetCode (69. Sqrt(x)) / GeeksForGeeks
Difficulty: Easy

Approach 1: Linear Search. Try numbers from 1 upwards until i * i > x. Return i - 1. Time Complexity: O(sqrt(x)).
Optimal Approach: Binary Search. Use binary search over the range [1, x]. 
For x < 2, the square root is x.
Let low = 1, high = x.
While low <= high:
  mid = low + (high - low) / 2
  If mid * mid == x, return mid.
  If mid * mid < x, mid is a candidate. Record mid in `ans` and search in the right half (low = mid + 1) to find if there's a larger value.
  If mid * mid > x, search in the left half (high = mid - 1).
To prevent overflow, we can use division: `mid <= x / mid` instead of `mid * mid <= x`.

Time Complexity: O(log x) worst and average case.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search / Find Peak / Upper Bound-like Search Space
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int low = 1, high = x;
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Using division to prevent potential integer overflow from mid * mid
            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1; // Try to find a larger candidate
            } else {
                high = mid - 1; // Too large, search left
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Zero
    assert(sol.mySqrt(0) == 0);

    // Test Case 2: One
    assert(sol.mySqrt(1) == 1);

    // Test Case 3: Four (Perfect Square)
    assert(sol.mySqrt(4) == 2);

    // Test Case 4: Eight (Non-perfect square, floor is 2)
    assert(sol.mySqrt(8) == 2);

    // Test Case 5: Large perfect square
    assert(sol.mySqrt(16) == 4);

    // Test Case 6: Prime number
    assert(sol.mySqrt(17) == 4);

    // Test Case 7: Large value
    assert(sol.mySqrt(2147395599) == 46339);

    // Test Case 8: Large limit value (INT_MAX - 1)
    assert(sol.mySqrt(2147483646) == 46340);

    std::cout << "Square Root Binary Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
