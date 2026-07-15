/*
Problem Name: Permutation in String
Platform: LeetCode
Difficulty: Medium

Approach: Sliding Window with Frequency Arrays. We count the frequency of characters in s1 and in the first window of size s1.size() in s2. Then we slide the window of size s1.size() across s2, updating the frequencies in O(1) time and checking if they match.

Time Complexity: O(n + m) where n is s1.size() and m is s2.size(). We traverse both strings at most once.
Space Complexity: O(1) since the alphabet size is constant (26 lowercase English letters).

Pattern: Sliding Window
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        // Frequency of s1
        for (char ch : s1)
            freq1[ch - 'a']++;

        // First window of s2
        for (int i = 0; i < n; i++)
            freq2[s2[i] - 'a']++;

        // Check first window
        if (freq1 == freq2)
            return true;

        // Slide the window
        for (int i = n; i < m; i++) {
            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - n] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    assert(sol.checkInclusion("ab", "eidbaooo") == true);
    assert(sol.checkInclusion("ab", "eidboaoo") == false);
    assert(sol.checkInclusion("a", "ab") == true);
    assert(sol.checkInclusion("adc", "dcda") == true);
    
    std::cout << "Permutation in String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
