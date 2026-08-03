/*
Problem Name: Strings Rotations of Each Other
Platform: GeeksForGeeks / LeetCode
Difficulty: Easy

Approach:
1. If the lengths of s1 and s2 are not equal, return false immediately.
2. Concatenate s1 with itself (temp = s1 + s1).
3. If s2 is a rotation of s1, it must occur as a substring inside temp.
   Note: Concatenating s1 + s2 is incorrect because s2 would always be found as a suffix if lengths match,
   giving false positives for non-rotation strings. Concatenating s1 + s1 properly spans all possible rotational permutations.
4. Use string::find to search for s2 in temp. Return true if found, false otherwise.

Time Complexity: O(n) where n is the length of s1
Space Complexity: O(n) to store the concatenated string s1 + s1

Pattern: String Manipulation / Substring Search
*/

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    bool areRotations(std::string &s1, std::string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        std::string temp = s1 + s1;
        return temp.find(s2) != std::string::npos;
    }
};

int main() {
    Solution sol;

    std::string s1 = "geeksforgeeks";
    std::string s2 = "forgeeksgeeks";
    assert(sol.areRotations(s1, s2) == true);

    std::string s3 = "mightandmagic";
    std::string s4 = "andmagicmight";
    assert(sol.areRotations(s3, s4) == true);

    std::string s5 = "abcd";
    std::string s6 = "acbd";
    assert(sol.areRotations(s5, s6) == false);

    std::string s7 = "abc";
    std::string s8 = "def";
    assert(sol.areRotations(s7, s8) == false);

    std::string s9 = "a";
    std::string s10 = "a";
    assert(sol.areRotations(s9, s10) == true);

    std::cout << "Strings Rotations of Each Other C++: All tests passed! 🎉" << std::endl;
    return 0;
}
