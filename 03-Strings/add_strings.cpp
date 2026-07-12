/*
Problem Name: Add Strings
Platform: LeetCode
Difficulty: Easy

Approach:
1. Initialize pointers at the end of both strings (num1 and num2).
2. Loop while there are digits left in either string, or there is a non-zero carry.
3. In each iteration, add the digits (if they exist) and the carry.
4. Push the last digit of the sum to the answer string, and update the carry.
5. Reverse the answer string to get the final result.

Time Complexity: O(max(N, M)) where N and M are the lengths of num1 and num2.
Space Complexity: O(1) auxiliary space (excluding the output string).

Pattern: String Manipulation / Math
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int endFirst = num1.size() - 1;
        int endSecond = num2.size() - 1;

        int carry = 0;
        std::string ans = "";

        while (endFirst >= 0 || endSecond >= 0 || carry != 0) {
            int sum = carry;

            if (endFirst >= 0) {
                sum += num1[endFirst] - '0';
                endFirst--;
            }

            if (endSecond >= 0) {
                sum += num2[endSecond] - '0';
                endSecond--;
            }

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard addition without carry overflow at the end
    assert(sol.addStrings("11", "123") == "134");

    // Test Case 2: Standard addition with carry overflow
    assert(sol.addStrings("456", "77") == "533");

    // Test Case 3: Adding zero
    assert(sol.addStrings("0", "0") == "0");

    // Test Case 4: Large numbers
    assert(sol.addStrings("9999", "1") == "10000");

    std::cout << "Add Strings C++: All tests passed! 🎉" << std::endl;
    return 0;
}
