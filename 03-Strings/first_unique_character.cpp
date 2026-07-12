/*
Problem Name: First Unique Character in a String
Platform: LeetCode
Difficulty: Easy

Approach:
1. Initialize a frequency array/vector of size 26 to store the count of each lowercase English letter.
2. Iterate through the string to populate the frequency counts.
3. Iterate through the string a second time, returning the index of the first character whose frequency is 1.
4. If no unique character is found, return -1.

Time Complexity: O(n)
Space Complexity: O(1) (fixed size frequency array of 26 elements)

Pattern: Frequency Counter
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard string
    std::string s1 = "leetcode";
    assert(sol.firstUniqChar(s1) == 0);

    // Test Case 2: Another standard string
    std::string s2 = "loveleetcode";
    assert(sol.firstUniqChar(s2) == 2);

    // Test Case 3: No unique character
    std::string s3 = "aabb";
    assert(sol.firstUniqChar(s3) == -1);

    std::cout << "First Unique Character in a String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
