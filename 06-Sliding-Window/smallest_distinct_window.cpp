/*
Problem Name: Smallest window that contains all characters of string itself (Smallest Distinct Window)
Platform: GeeksforGeeks
Difficulty: Medium

Approach: Sliding Window using an Unordered Set & Map. 
1. First, we identify all the unique characters present in the entire string using an unordered set.
2. We then maintain a sliding window [left, right]. We expand the window by moving the right pointer and record the character frequencies in an unordered map.
3. When the count of unique characters in the current window matches the required count of unique characters in the entire string, we try to minimize the window by shrinking it from the left until the condition is no longer met.

Time Complexity: O(n) where n is the length of the string. Both pointers traverse the string at most once.
Space Complexity: O(k) where k is the number of distinct characters in the string (at most 256).

Pattern: Sliding Window
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cassert>

class Solution {
public:
    int findSubString(std::string &str) {
        std::unordered_set<char> st;

        // Count total distinct characters
        for (char ch : str)
            st.insert(ch);

        int required = st.size();
        std::unordered_map<char, int> mp;

        int left = 0;
        int count = 0;
        int ans = INT_MAX;

        for (int right = 0; right < str.size(); right++) {
            mp[str[right]]++;

            if (mp[str[right]] == 1)
                count++;

            while (count == required) {
                ans = std::min(ans, right - left + 1);

                mp[str[left]]--;

                if (mp[str[left]] == 0) {
                    count--;
                }

                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    std::string test1 = "AABCBCDA";
    assert(sol.findSubString(test1) == 4); // "BCDA" has all unique characters: A, B, C, D
    
    std::string test2 = "aaab";
    assert(sol.findSubString(test2) == 2); // "ab" has 'a' and 'b'
    
    std::string test3 = "GEEKSFORGEEKS";
    assert(sol.findSubString(test3) == 7); // "KSFORGE" contains G, E, K, S, F, O, R

    std::string test4 = "a";
    assert(sol.findSubString(test4) == 1);
    
    std::cout << "Smallest Distinct Window C++: All tests passed! 🎉" << std::endl;
    return 0;
}
