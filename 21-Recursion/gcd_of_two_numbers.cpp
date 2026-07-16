/*
Problem Name: GCD of Two Numbers (Euclidean Algorithm)
Platform: GeeksForGeeks / General
Difficulty: Easy

Approach: Recursion (Euclidean Algorithm)
  The Euclidean Algorithm is based on the property:
    gcd(a, b) == gcd(b, a % b)

  Base Case : b == 0  →  return a
  Recursive : gcd(a, b) = gcd(b, a % b)

  Why it works:
    Any divisor of both a and b also divides (a % b),
    so gcd doesn't change when we replace a with b and b with a%b.

Time Complexity : O(log(min(a, b))) — number of steps ≈ Fibonacci growth
Space Complexity: O(log(min(a, b))) — recursion call stack depth
Pattern: Recursion / Math
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    int gcd(int a, int b) {
        // Base Case: when b becomes 0, a is the GCD
        if (b == 0)
            return a;

        // Recursive Case: gcd(a, b) = gcd(b, a % b)
        return gcd(b, a % b);
    }
};

int main() {
    Solution sol;

    // Test Case 1: gcd(12, 4) = 4
    assert(sol.gcd(12, 4) == 4);

    // Test Case 2: gcd(48, 18) = 6
    assert(sol.gcd(48, 18) == 6);

    // Test Case 3: gcd(7, 5) = 1  (coprime)
    assert(sol.gcd(7, 5) == 1);

    // Test Case 4: gcd(100, 75) = 25
    assert(sol.gcd(100, 75) == 25);

    // Test Case 5: gcd(0, 5) = 5
    assert(sol.gcd(0, 5) == 5);

    // Test Case 6: gcd(a, a) = a
    assert(sol.gcd(9, 9) == 9);

    // Print table for visual verification
    std::cout << "GCD Table (Euclidean Algorithm):\n";
    int pairs[][2] = {{12,4},{48,18},{56,98},{100,75},{7,5},{36,60},{270,192}};
    for (auto& p : pairs) {
        std::cout << "  gcd(" << p[0] << ", " << p[1] << ") = "
                  << sol.gcd(p[0], p[1]) << "\n";
    }

    std::cout << "\nGCD C++: All tests passed! 🎉" << std::endl;
    return 0;
}
