/*
Problem Name: Sort String
Platform: Custom / LeetCode
Difficulty: Easy

Approach:
1. Use a frequency array of size 26 to count the occurrences of each character in the string.
2. Reconstruct the string in alphabetical order by iterating through the frequency array.

Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1) auxiliary space (constant size 26 frequency array).

Pattern: Counting Sort / Frequency Counter
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    std::string sortString(std::string s) {
        std::vector<int> freq(26, 0);

        // Count frequency
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        std::string ans = "";

        // Rebuild sorted string
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += char(i + 'a');
                freq[i]--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard unsorted string
    std::string s1 = "leetcode";
    assert(sol.sortString(s1) == "cdeeelot");

    // Test Case 2: Already sorted string
    std::string s2 = "abc";
    assert(sol.sortString(s2) == "abc");

    // Test Case 3: All identical characters
    std::string s3 = "zzzz";
    assert(sol.sortString(s3) == "zzzz");

    std::cout << "Sort String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
