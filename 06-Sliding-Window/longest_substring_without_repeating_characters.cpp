/*
Problem Name: Longest Substring Without Repeating Characters
Platform: LeetCode
Difficulty: Medium

Approach 1: Sliding Window using Hash Set. We expand the window to the right and shrink from the left when a duplicate is found.
Optimal Approach: Sliding Window using an index map (direct array). Instead of erasing elements one by one, we directly jump the left pointer to the index after the last occurrence of the duplicate character.

Time Complexity: O(n)
Space Complexity: O(min(n, m)) where m is the character set size (e.g., 128 for ASCII).

Pattern: Sliding Window
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    // Approach 1: Sliding Window with Hash Set (User's approach)
    int lengthOfLongestSubstringSet(std::string s) {
        std::unordered_set<char> st;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }

    // Optimal Approach: Sliding Window with Index Mapping (direct array jump)
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> charIndex(128, -1); // Maps ASCII characters to their last seen index
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            if (charIndex[s[right]] != -1) {
                left = std::max(left, charIndex[s[right]] + 1);
            }
            charIndex[s[right]] = right;
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring("bbbbb") == 1);
    assert(sol.lengthOfLongestSubstring("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstring("") == 0);
    assert(sol.lengthOfLongestSubstring(" ") == 1);
    assert(sol.lengthOfLongestSubstring("au") == 2);
    assert(sol.lengthOfLongestSubstring("dvdf") == 3);

    // Assert Approach 1 (User's approach) to verify its correctness
    assert(sol.lengthOfLongestSubstringSet("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstringSet("bbbbb") == 1);
    assert(sol.lengthOfLongestSubstringSet("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstringSet("") == 0);
    assert(sol.lengthOfLongestSubstringSet(" ") == 1);
    assert(sol.lengthOfLongestSubstringSet("au") == 2);
    assert(sol.lengthOfLongestSubstringSet("dvdf") == 3);

    std::cout << "Longest Substring Without Repeating Characters C++: All tests passed! 🎉" << std::endl;
    return 0;
}
