/*
Problem Name: Reverse Words in a String (LeetCode 151)
Platform: LeetCode
Difficulty: Medium

Approach:
1. Reverse the entire string.
2. Reverse each individual word in-place.
3. Clean up extra spaces (leading, trailing, and multiple spaces between words) using a two-pointer write technique.

Time Complexity: O(N) where N is the length of string s.
Space Complexity: O(1) auxiliary space (in-place modification).

Pattern: Two Pointers / String Manipulation
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int n = s.size();

        // Step 1: Reverse the entire string
        std::reverse(s.begin(), s.end());

        // Step 2: Reverse each word & clean up extra spaces using two pointers
        int i = 0;
        int l = 0, r = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++; // Skip spaces
            }
            if (i >= n) break;

            if (l != 0) {
                s[l++] = ' '; // Add single space between words
            }

            r = l;
            while (i < n && s[i] != ' ') {
                s[l++] = s[i++];
            }

            // Reverse the current word back to its correct order
            std::reverse(s.begin() + r, s.begin() + l);
        }

        s.resize(l);
        return s;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard example
    assert(sol.reverseWords("the sky is blue") == "blue is sky the");

    // Test Case 2: Leading and trailing spaces
    assert(sol.reverseWords("  hello world  ") == "world hello");

    // Test Case 3: Multiple spaces between words
    assert(sol.reverseWords("a good   example") == "example good a");

    std::cout << "Reverse Words in a String (LeetCode 151) C++: All tests passed! 🎉" << std::endl;
    return 0;
}
