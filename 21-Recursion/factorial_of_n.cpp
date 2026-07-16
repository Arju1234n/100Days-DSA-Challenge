/*
Problem Name: Factorial of N
Platform: General / LeetCode style
Difficulty: Easy

Approach: Recursion
  - Base Case: factorial(0) = 1  (0! = 1 by definition)
  - Recursive Case: factorial(n) = n * factorial(n - 1)

Time Complexity : O(N) — one multiplication per call
Space Complexity: O(N) — recursion call stack depth
Pattern: Recursion
*/

#include <iostream>
#include <cassert>

// Returns the factorial of n  (n!)
long long factorial(int n) {
    // Base Case
    if (n == 0)
        return 1;

    // Recursive Case: n! = n * (n-1)!
    return (long long)n * factorial(n - 1);
}

int main() {
    // Test Case 1: 0! = 1
    assert(factorial(0) == 1);

    // Test Case 2: 1! = 1
    assert(factorial(1) == 1);

    // Test Case 3: 5! = 120
    assert(factorial(5) == 120);

    // Test Case 4: 10! = 3628800
    assert(factorial(10) == 3628800);

    // Print table for visual verification
    std::cout << "Factorial table (0 to 12):\n";
    for (int i = 0; i <= 12; ++i) {
        std::cout << i << "! = " << factorial(i) << "\n";
    }

    std::cout << "Factorial C++: All tests passed! 🎉" << std::endl;
    return 0;
}
