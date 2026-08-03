/*
Problem Name: Maximum Occurring Character
Platform: GeeksForGeeks
Difficulty: Easy

Approach:
1. Create a frequency vector of size 26 initialized to 0 to store counts of characters ('a' through 'z').
2. Iterate through string `s` and increment the count for each character `freq[s[i] - 'a']`.
3. Iterate through frequency array from index 0 ('a') to 25 ('z').
4. Maintain `maxi` for maximum frequency and `ans` for the corresponding character.
   Using strict inequality `freq[i] > maxi` ensures that in case of ties, the lexicographically smallest character is returned.

Time Complexity: O(n) where n is the length of string s.
Space Complexity: O(1) for fixed size 26 frequency array.

Pattern: Frequency Map / Hashing
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    char getMaxOccuringChar(std::string& s) {
        std::vector<int> freq(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        
        int maxi = 0;
        char ans = 'a';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxi) {
                maxi = freq[i];
                ans = i + 'a';
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    std::string s1 = "testsample";
    assert(sol.getMaxOccuringChar(s1) == 'e');

    std::string s2 = "output";
    assert(sol.getMaxOccuringChar(s2) == 't');

    // Tie-breaker test: 'a' and 'b' both appear 2 times, should return lexicographically smaller ('a')
    std::string s3 = "abab";
    assert(sol.getMaxOccuringChar(s3) == 'a');

    std::string s4 = "z";
    assert(sol.getMaxOccuringChar(s4) == 'z');

    std::cout << "Maximum Occurring Character C++: All tests passed! 🎉" << std::endl;
    return 0;
}
