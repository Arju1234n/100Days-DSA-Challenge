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
    
    // Test Case 1
    assert(sol.isAnagram("anagram", "nagaram") == true);
    
    // Test Case 2
    assert(sol.isAnagram("rat", "car") == false);
    
    // Test Case 3
    assert(sol.isAnagram("a", "ab") == false);
    
    std::cout << "Day 2 (Valid Anagram) C++: All tests passed successfully! 🎉" << std::endl;
    return 0;
}
