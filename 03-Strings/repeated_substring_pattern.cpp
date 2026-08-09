#include <iostream>
#include <string>

using namespace std;

// Problem Name: Repeated Substring Pattern
// Platform: LeetCode 459
// Difficulty: Easy
// Time Complexity: O(N) where N is the length of string s
// Space Complexity: O(N) for concatenated string temp
//
// Approach: String Doubling Trick
// If s is composed of a repeated sub-pattern, concatenating s with itself (s + s)
// will contain s somewhere inside it, starting from an index between 1 and s.size() - 1.
// By trimming the first and last characters of s + s, we check if s is still present.

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        return temp.substr(1, temp.size() - 2).find(s) != string::npos;
    }
};

int main() {
    Solution sol;
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "abcabcabcabc";

    cout << boolalpha;
    cout << "s1 (\"abab\"): " << sol.repeatedSubstringPattern(s1) << endl; // true
    cout << "s2 (\"aba\"): " << sol.repeatedSubstringPattern(s2) << endl;  // false
    cout << "s3 (\"abcabcabcabc\"): " << sol.repeatedSubstringPattern(s3) << endl; // true

    return 0;
}
