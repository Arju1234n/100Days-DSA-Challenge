#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3 ("abc")
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1 ("b")
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3 ("wke")
    return 0;
}
