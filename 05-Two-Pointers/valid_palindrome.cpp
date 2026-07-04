/*
Problem Name: Valid Palindrome
Platform: LeetCode
Difficulty: Easy

Approach 1: Reverse string and compare. Uses O(n) space.
Approach 2: Two pointers moving inwards comparing valid alphanumeric characters.
Optimal Approach: Two pointers moving inwards in-place.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Two Pointers
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }
            
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    assert(sol.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(sol.isPalindrome("race a car") == false);
    std::cout << "Valid Palindrome C++: All tests passed! 🎉" << std::endl;
    return 0;
}
