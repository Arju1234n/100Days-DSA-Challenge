/*
Problem Name: Check if String is Rotated by Two Places
Platform: GeeksForGeeks
Difficulty: Easy

Approach:
1. If the lengths of s1 and s2 are not equal, return false.
2. For strings of length <= 2, left or right rotation by 2 places yields the same string, so return s1 == s2.
3. Construct the left-rotated string by concatenating the substring from index 2 to end with the substring of the first 2 characters.
4. Construct the right-rotated string by concatenating the substring of the last 2 characters with the substring from start to index n-2.
5. Return true if s2 matches either the left-rotated or right-rotated versions.

Time Complexity: O(n)
Space Complexity: O(n) to store the rotated strings.

Pattern: String Manipulation
*/

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    bool isRotated(std::string s1, std::string s2) {
        if (s1.size() != s2.size())
            return false;

        int n = s1.size();

        // Edge case
        if (n <= 2)
            return s1 == s2;

        std::string left = s1.substr(2) + s1.substr(0, 2);
        std::string right = s1.substr(n - 2) + s1.substr(0, n - 2);

        return (left == s2 || right == s2);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Left rotation by 2 places
    assert(sol.isRotated("amazon", "azonam") == true);

    // Test Case 2: Right rotation by 2 places
    assert(sol.isRotated("amazon", "onamaz") == true);

    // Test Case 3: Not rotated by 2 places
    assert(sol.isRotated("amazon", "amazon") == false);

    // Test Case 4: Length <= 2
    assert(sol.isRotated("ab", "ab") == true);
    assert(sol.isRotated("ab", "ba") == false);

    std::cout << "Check if String is Rotated by Two Places C++: All tests passed! 🎉" << std::endl;
    return 0;
}
