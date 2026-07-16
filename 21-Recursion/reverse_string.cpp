/*
Problem Name: Reverse a String (Recursive)
Platform: LeetCode #344
Difficulty: Easy

Approach: Recursion (Two-Pointer style)
  Swap the outermost characters, then recursively reverse the inner substring.
  Base Case: lo >= hi → nothing left to swap (0 or 1 character remaining)
  Recursive : swap(s[lo], s[hi])  →  reverse(lo+1, hi-1)

Time Complexity : O(N) — N/2 swaps
Space Complexity: O(N) — recursion call stack depth
Pattern: Recursion / Two Pointers
*/

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

class Solution {
public:
    void reverseHelper(std::string& s, int lo, int hi) {
        // Base Case: pointers meet or cross
        if (lo >= hi)
            return;

        // Swap outermost characters
        std::swap(s[lo], s[hi]);

        // Recurse on inner substring
        reverseHelper(s, lo + 1, hi - 1);
    }

    std::string reverseString(std::string s) {
        reverseHelper(s, 0, (int)s.size() - 1);
        return s;
    }
};

int main() {
    Solution sol;

    // Test 1: even length
    assert(sol.reverseString("hello") == "olleh");

    // Test 2: odd length
    assert(sol.reverseString("Hannah") == "hannaH");

    // Test 3: single character
    assert(sol.reverseString("a") == "a");

    // Test 4: empty string
    assert(sol.reverseString("") == "");

    // Test 5: already reversed
    assert(sol.reverseString("abcde") == "edcba");

    // Print demo
    std::vector<std::string> words = {"hello", "recursion", "racecar", "OpenAI"};
    std::cout << "Reverse String demo:\n";
    for (auto& w : words) {
        std::cout << "  \"" << w << "\" → \"" << sol.reverseString(w) << "\"\n";
    }

    std::cout << "\nReverse String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
