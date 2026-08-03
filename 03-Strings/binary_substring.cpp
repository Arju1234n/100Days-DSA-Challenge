/*
Problem Name: Binary String
Platform: GeeksForGeeks
Difficulty: Easy

Approach:
1. Count the total number of '1's in the binary string `s`, say `k`.
2. Any valid substring starting and ending with '1' is determined by choosing a pair of distinct indices (i, j) where both s[i] and s[j] are '1' (i < j).
3. The number of ways to choose 2 indices out of `k` ones is given by the combination formula: k * (k - 1) / 2.

Time Complexity: O(n) where n is the length of string s
Space Complexity: O(1)

Pattern: Combinatorics / Counting
*/

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    int binarySubstring(std::string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            }
        }
        return count * (count - 1) / 2;
    }
};

int main() {
    Solution sol;

    std::string s1 = "1111";
    assert(sol.binarySubstring(s1) == 6);

    std::string s2 = "011011";
    assert(sol.binarySubstring(s2) == 6);

    std::string s3 = "0000";
    assert(sol.binarySubstring(s3) == 0);

    std::string s4 = "1";
    assert(sol.binarySubstring(s4) == 0);

    std::cout << "Binary String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
