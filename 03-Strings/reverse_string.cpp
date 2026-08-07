/*
Problem Name: Reverse String (LeetCode 344)
Platform: LeetCode
Difficulty: Easy

Approach:
1. Two Pointers. Maintain one pointer at the start (left = 0) and one at the end (right = s.size() - 1).
2. Swap characters at left and right pointers in-place.
3. Increment left pointer and decrement right pointer until left >= right.

Time Complexity: O(N) where N is the length of vector s.
Space Complexity: O(1) auxiliary space (in-place modification).

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1: LeetCode 344 Example 1
    std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> expected1 = {'o', 'l', 'l', 'e', 'h'};
    sol.reverseString(s1);
    assert(s1 == expected1);

    // Test Case 2: LeetCode 344 Example 2
    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> expected2 = {'h', 'a', 'n', 'n', 'a', 'H'};
    sol.reverseString(s2);
    assert(s2 == expected2);

    std::cout << "Reverse String (LeetCode 344) C++: All tests passed! 🎉" << std::endl;
    return 0;
}
