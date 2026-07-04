/*
Problem Name: Valid Anagram
Platform: LeetCode
Difficulty: Easy

Approach 1: Sorting both strings and comparing (O(n log n) time).
Approach 2: Character frequency count using hash map or fixed array of size 26.
Optimal Approach: Single hash map / array frequency counter.

Time Complexity: O(n)
Space Complexity: O(1) - since alphabet size is fixed to 26

Pattern: Hashing / Frequency Map
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        std::unordered_map<char, int> char_counts;
        for (char c : s) {
            char_counts[c]++;
        }
        
        for (char c : t) {
            if (char_counts.find(c) == char_counts.end()) {
                return false;
            }
            char_counts[c]--;
            if (char_counts[c] == 0) {
                char_counts.erase(c);
            }
        }
        
        return char_counts.empty();
    }
};

int main() {
    Solution sol;
    assert(sol.isAnagram("anagram", "nagaram") == true);
    assert(sol.isAnagram("rat", "car") == false);
    std::cout << "Valid Anagram C++: All tests passed! 🎉" << std::endl;
    return 0;
}
