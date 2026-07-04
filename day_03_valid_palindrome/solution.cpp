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
    
    // Test Case 1
    assert(sol.isPalindrome("A man, a plan, a canal: Panama") == true);
    
    // Test Case 2
    assert(sol.isPalindrome("race a car") == false);
    
    // Test Case 3
    assert(sol.isPalindrome(" ") == true);
    
    std::cout << "Day 3 (Valid Palindrome) C++: All tests passed successfully! 🎉" << std::endl;
    return 0;
}
