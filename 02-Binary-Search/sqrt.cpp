/*
Problem Name: Square Root of an Integer (Floor Sqrt)
Platform: LeetCode (69. Sqrt(x)) / GeeksforGeeks (Floor Sqrt)
Difficulty: Easy

Approach 1: Linear Search. Try numbers from 1 upwards until i * i > x. Return i - 1. Time Complexity: O(sqrt(x)).
Optimal Approach: Binary Search over range [1, n / 2].
For n < 2, return n.
Set left = 1, right = n / 2, ans = 1.
While left <= right:
  mid = left + (right - left) / 2
  If mid * mid <= n:
      ans = mid, left = mid + 1 (search right for larger square root)
  Else:
      right = mid - 1 (search left)

Time Complexity: O(log n)
Space Complexity: O(1) auxiliary space

Pattern: Binary Search
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    int floorSqrt(int n) {
        if (n < 2)
            return n;

        long long left = 1;
        long long right = n / 2;
        long long ans = 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid <= n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int mySqrt(int x) {
        return floorSqrt(x);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Zero
    assert(sol.floorSqrt(0) == 0);

    // Test Case 2: One
    assert(sol.floorSqrt(1) == 1);

    // Test Case 3: Four (Perfect Square)
    assert(sol.floorSqrt(4) == 2);

    // Test Case 4: Eight (Non-perfect square, floor is 2)
    assert(sol.floorSqrt(8) == 2);

    // Test Case 5: Large perfect square
    assert(sol.floorSqrt(16) == 4);

    // Test Case 6: Prime number
    assert(sol.floorSqrt(17) == 4);

    // Test Case 7: Large value
    assert(sol.floorSqrt(2147395599) == 46339);

    // Test Case 8: Large limit value (INT_MAX - 1)
    assert(sol.floorSqrt(2147483646) == 46340);

    std::cout << "Square Root Binary Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
