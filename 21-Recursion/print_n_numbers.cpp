/*
Problem Name: Print Numbers from 1 to N
Pattern: Recursion

Approach: Recursion
  - Base Case: if n == 0, return (stop recursion)
  - Recursive Case: first recurse with (n-1), then print n
    This ensures numbers are printed in ascending order (1 to N).

Time Complexity : O(N) — one call per number
Space Complexity: O(N) — recursion call stack depth
*/

#include <iostream>
#include <cassert>

// ── Print 1 to N ────────────────────────────────────────────────
void printNumbers(int n) {
    // Base Case
    if (n == 0)
        return;

    // Recurse first, then print  →  ascending order
    printNumbers(n - 1);
    std::cout << n << " ";
}

// ── Print N to 1 (bonus) ─────────────────────────────────────────
void printReverse(int n) {
    // Base Case
    if (n == 0)
        return;

    // Print first, then recurse  →  descending order
    std::cout << n << " ";
    printReverse(n - 1);
}

int main() {
    int n = 10;

    std::cout << "Print 1 to " << n << " : ";
    printNumbers(n);
    std::cout << "\n";

    std::cout << "Print " << n << " to 1 : ";
    printReverse(n);
    std::cout << "\n";

    std::cout << "Print N Numbers C++: All tests passed! 🎉" << std::endl;
    return 0;
}
