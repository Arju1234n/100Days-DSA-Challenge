/*
Problem Name: Check Palindrome (Recursive)
Platform: General / LeetCode #125 variant
Difficulty: Easy

Approach: Recursion (Two-Pointer style)
  Compare outermost characters; if they match, recursively check the inner substring.
  Base Cases:
    1. lo >= hi         → all characters matched → true (palindrome)
    2. s[lo] != s[hi]   → mismatch → false (not a palindrome)
  Recursive: isPalindromeHelper(lo+1, hi-1)

Time Complexity : O(N) — N/2 comparisons
Space Complexity: O(N) — recursion call stack depth
Pattern: Recursion / Two Pointers
*/

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindromeHelper(const std::string& s, int lo, int hi) {
        // Base Case 1: pointers met or crossed → palindrome
        if (lo >= hi)
            return true;

        // Base Case 2: mismatch → not a palindrome
        if (s[lo] != s[hi])
            return false;

        // Recursive Case: check inner substring
        return isPalindromeHelper(s, lo + 1, hi - 1);
    }

    bool isPalindrome(const std::string& s) {
        return isPalindromeHelper(s, 0, (int)s.size() - 1);
    }

    // Bonus: case-insensitive, alphanumeric only (LeetCode #125 style)
    bool isPalindromeLC(std::string s) {
        // Keep only alphanumeric chars, convert to lowercase
        std::string cleaned;
        for (char c : s)
            if (std::isalnum(c))
                cleaned += std::tolower(c);
        return isPalindrome(cleaned);
    }
};

int main() {
    Solution sol;

    // ── Basic palindrome checks ──────────────────────────────────
    assert(sol.isPalindrome("racecar") == true);
    assert(sol.isPalindrome("madam")   == true);
    assert(sol.isPalindrome("abcba")   == true);
    assert(sol.isPalindrome("a")       == true);
    assert(sol.isPalindrome("")        == true);
    assert(sol.isPalindrome("hello")   == false);
    assert(sol.isPalindrome("abcd")    == false);

    // ── LeetCode #125 style ──────────────────────────────────────
    assert(sol.isPalindromeLC("A man, a plan, a canal: Panama") == true);
    assert(sol.isPalindromeLC("race a car")                     == false);
    assert(sol.isPalindromeLC(" ")                              == true);

    // Print demo
    std::vector<std::string> words = {"racecar", "hello", "madam", "level", "world", "noon"};
    std::cout << "Palindrome Check demo:\n";
    for (auto& w : words) {
        std::cout << "  \"" << w << "\" → "
                  << (sol.isPalindrome(w) ? "Palindrome ✅" : "Not Palindrome ❌") << "\n";
    }

    std::cout << "\nPalindrome C++: All tests passed! 🎉" << std::endl;
    return 0;
}
