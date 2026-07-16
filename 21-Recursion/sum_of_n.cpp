/*
Problem Name: Sum of First N Natural Numbers
Platform: General
Difficulty: Easy

Approach: Recursion
  - Base Case: sum(0) = 0
  - Recursive Case: sum(n) = n + sum(n - 1)

Time Complexity : O(N) — one addition per call
Space Complexity: O(N) — recursion call stack depth
Pattern: Recursion
*/

#include <iostream>
#include <cassert>

// Returns the sum of first n natural numbers: 1 + 2 + ... + n
long long sumOfN(int n) {
    // Base Case
    if (n == 0)
        return 0;

    // Recursive Case: sum(n) = n + sum(n-1)
    return n + sumOfN(n - 1);
}

int main() {
    // Test Case 1: sum(0) = 0
    assert(sumOfN(0) == 0);

    // Test Case 2: sum(1) = 1
    assert(sumOfN(1) == 1);

    // Test Case 3: sum(5) = 15  (1+2+3+4+5)
    assert(sumOfN(5) == 15);

    // Test Case 4: sum(10) = 55
    assert(sumOfN(10) == 55);

    // Test Case 5: sum(100) = 5050
    assert(sumOfN(100) == 5050);

    // Print results for visual verification
    std::cout << "Sum of first N natural numbers:\n";
    for (int i = 0; i <= 10; ++i) {
        std::cout << "sum(1.." << i << ") = " << sumOfN(i) << "\n";
    }

    std::cout << "Sum of N C++: All tests passed! 🎉" << std::endl;
    return 0;
}
