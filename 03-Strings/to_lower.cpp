/*
Problem Name: To Lower Case
Platform: LeetCode
Difficulty: Easy

Approach: Iterate through each character of the string and convert it to its lowercase equivalent using std::tolower.

Time Complexity: O(n)
Space Complexity: O(1) in-place modification

Pattern: String Manipulation
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

class Solution {
public:
    std::string toLower(std::string& s) {
        for (size_t i = 0; i < s.size(); i++) {
            s[i] = std::tolower(s[i]);
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard uppercase/lowercase mixed
    std::string s1 = "Hello";
    assert(sol.toLower(s1) == "hello");

    // Test Case 2: All uppercase
    std::string s2 = "LOVELY";
    assert(sol.toLower(s2) == "lovely");

    // Test Case 3: Already lowercase
    std::string s3 = "here";
    assert(sol.toLower(s3) == "here");

    // Test Case 4: Numbers and symbols
    std::string s4 = "123#A!";
    assert(sol.toLower(s4) == "123#a!");

    std::cout << "To Lower Case C++: All tests passed! 🎉" << std::endl;
    return 0;
}
