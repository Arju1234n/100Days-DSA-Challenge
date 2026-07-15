/*
Problem Name: Fibonacci Number
Platform: LeetCode
Difficulty: Easy

Approach 1: Recursion
The Fibonacci numbers are recursively defined as:
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1.
This implementation uses simple recursion.

Time Complexity: O(2^N) due to redundant calculation of subproblems.
Space Complexity: O(N) auxiliary space used by the recursion call stack.

Pattern: Recursion
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    int fib(int n) {
        // Base Case
        if (n <= 1)
            return n;

        // Recursive Case
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 2 -> 1
    assert(sol.fib(2) == 1);

    // Test Case 2: n = 3 -> 2
    assert(sol.fib(3) == 2);

    // Test Case 3: n = 4 -> 3
    assert(sol.fib(4) == 3);

    // Test Case 4: n = 9 -> 34
    assert(sol.fib(9) == 34);

    std::cout << "Fibonacci Number C++: All tests passed! 🎉" << std::endl;
    return 0;
}
