/*
Problem Name: Factorials of Large Numbers
Platform: GeeksForGeeks
Difficulty: Medium

Approach 1: Array representation of large integers.
We represent the large number as a vector of digits, starting from the least significant digit at index 0.
When multiplying by x, we multiply each digit, add the carry, and update the array, propagating the carry to the next digits.
At the end, we reverse the vector to get the final representation from most significant to least significant.

Time Complexity: O(N^2) where N is the input number. The number of digits in N! is O(N log N).
Space Complexity: O(D) where D is the number of digits in N!, which is O(N log N).

Pattern: Math / Big Integer Multiplication
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<int> factorial(int n) {
        std::vector<int> ans;
        ans.push_back(1);

        for (int x = 2; x <= n; x++) {
            int carry = 0;
            for (size_t i = 0; i < ans.size(); i++) {
                int product = ans[i] * x + carry;
                ans[i] = product % 10;
                carry = product / 10;
            }
            while (carry > 0) {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: 5! = 120
    std::vector<int> expected1 = {1, 2, 0};
    assert(sol.factorial(5) == expected1);

    // Test Case 2: 1! = 1
    std::vector<int> expected2 = {1};
    assert(sol.factorial(1) == expected2);

    // Test Case 3: 10! = 3628800
    std::vector<int> expected3 = {3, 6, 2, 8, 8, 0, 0};
    assert(sol.factorial(10) == expected3);

    std::cout << "Factorials of Large Numbers C++: All tests passed! 🎉" << std::endl;
    return 0;
}
