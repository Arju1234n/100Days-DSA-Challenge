/*
Problem Name: Merge Strings Alternately (LeetCode 1768)
Platform: LeetCode
Difficulty: Easy

Approach:
1. Use two pointers i and j initialized to 0 for word1 and word2 respectively.
2. Interleave characters from word1 and word2 while both indices are within bounds.
3. Append any remaining characters from word1 or word2.

Time Complexity: O(N + M) where N and M are the lengths of word1 and word2.
Space Complexity: O(1) auxiliary space (excluding the output string).

Pattern: Two Pointers / String Manipulation
*/

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string ans = "";

        int i = 0;
        int j = 0;

        while (i < word1.size() && j < word2.size()) {
            ans += word1[i];
            ans += word2[j];

            i++;
            j++;
        }

        while (i < word1.size()) {
            ans += word1[i];
            i++;
        }

        while (j < word2.size()) {
            ans += word2[j];
            j++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    assert(sol.mergeAlternately("abc", "pqr") == "apbqcr");

    // Test Case 2
    assert(sol.mergeAlternately("ab", "pqrs") == "apbqrs");

    // Test Case 3
    assert(sol.mergeAlternately("abcd", "pq") == "apbqcd");

    std::cout << "Merge Strings Alternately C++: All tests passed! 🎉" << std::endl;
    return 0;
}
