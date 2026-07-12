/*
Problem Name: Reverse a String
Platform: GeeksForGeeks / LeetCode
Difficulty: Easy

Approach 1: Two Pointers. Maintain one pointer at the start (left = 0) and one at the end (right = s.size() - 1). Swap elements at these pointers, then increment left and decrement right until they meet or cross.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space (in-place modification)

Pattern: Two Pointers
*/

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

class Solution {
public:
    std::string reverseString(std::string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard string
    std::string s1 = "hello";
    std::string expected1 = "olleh";
    assert(sol.reverseString(s1) == expected1);

    // Test Case 2: Even length string
    std::string s2 = "Geeks";
    std::string expected2 = "skeeG";
    assert(sol.reverseString(s2) == expected2);

    // Test Case 3: Empty string
    std::string s3 = "";
    std::string expected3 = "";
    assert(sol.reverseString(s3) == expected3);

    // Test Case 4: Single character string
    std::string s4 = "a";
    std::string expected4 = "a";
    assert(sol.reverseString(s4) == expected4);

    std::cout << "Reverse String C++: All tests passed! 🎉" << std::endl;
    return 0;
}
