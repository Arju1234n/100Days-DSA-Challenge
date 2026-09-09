/*
Problem Name: Longest Palindrome (LeetCode 409)
Platform: LeetCode
Difficulty: Easy

Approach 1: Hash Map / Frequency Array to count occurrences of each character.
Optimal Approach: For each character, add the largest even number of its count (count - count % 2) 
to the palindrome length. If there is at least one character with an odd frequency, 
we can place one odd character in the center of the palindrome (+1).

Time Complexity: O(n) - Single pass over string of length n.
Space Complexity: O(1) - Fixed size frequency array / hash table for ASCII characters.

Pattern: Hash Table / Counting / Greedy
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (const auto& [ch, count] : freq) {
            length += (count / 2) * 2;
            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case with mixed cases and multiple odd/even frequencies
    // "abccccdd" -> 'c': 4, 'd': 2, 'a': 1, 'b': 1 -> 4 + 2 + 1 = 7 (e.g. "dccaccd")
    assert(sol.longestPalindrome("abccccdd") == 7);

    // Test Case 2: Single character
    assert(sol.longestPalindrome("a") == 1);

    // Test Case 3: Case sensitivity test ("Aa" cannot form a palindrome of length 2)
    assert(sol.longestPalindrome("Aa") == 1);

    // Test Case 4: All even counts
    assert(sol.longestPalindrome("aabbcc") == 6);

    // Test Case 5: All unique characters
    assert(sol.longestPalindrome("abcdef") == 1);

    // Test Case 6: Multiple odds
    assert(sol.longestPalindrome("ccc") == 3);

    std::cout << "Longest Palindrome C++: All tests passed! 🎉" << std::endl;
    return 0;
}
