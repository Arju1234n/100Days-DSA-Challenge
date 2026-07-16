/*
Problem Name: Climbing Stairs
Platform: LeetCode #70
Difficulty: Easy

Approach: Recursion
  You can climb either 1 or 2 steps at a time.
  The number of ways to reach step n equals:
    ways(n) = ways(n-1) + ways(n-2)
  This is identical to the Fibonacci sequence!

  Base Cases:
    n == 1 → 1 way  (one step of size 1)
    n == 2 → 2 ways (1+1  or  2)

Time Complexity : O(2^N) — overlapping subproblems recalculated (naive recursion)
Space Complexity: O(N)   — recursion call stack depth

Note: Can be optimised to O(N) time with memoization (DP).
Pattern: Recursion / Dynamic Programming
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    int climbStairs(int n) {
        // Base Cases
        if (n <= 2)
            return n;

        // Recursive Case: reach step n from step (n-1) or step (n-2)
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 1 → 1 way
    assert(sol.climbStairs(1) == 1);

    // Test Case 2: n = 2 → 2 ways  (1+1 or 2)
    assert(sol.climbStairs(2) == 2);

    // Test Case 3: n = 3 → 3 ways  (1+1+1, 1+2, 2+1)
    assert(sol.climbStairs(3) == 3);

    // Test Case 4: n = 4 → 5 ways
    assert(sol.climbStairs(4) == 5);

    // Test Case 5: n = 5 → 8 ways
    assert(sol.climbStairs(5) == 8);

    // Print table for visual verification
    std::cout << "Climbing Stairs — ways to reach step N:\n";
    for (int i = 1; i <= 10; ++i) {
        std::cout << "  n = " << i << " → " << sol.climbStairs(i) << " ways\n";
    }

    std::cout << "\nClimbing Stairs C++: All tests passed! 🎉" << std::endl;
    return 0;
}
