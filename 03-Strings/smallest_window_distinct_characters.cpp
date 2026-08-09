#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Problem Name: Smallest Window Containing All Distinct Characters / Smallest Substring
// Platform: GeeksforGeeks
// Difficulty: Medium
// Time Complexity: O(N)
// Space Complexity: O(1) - fixed frequency array of size 256

class Solution {
public:
    int findSubString(string& s) {
        vector<int> freq(256, 0);

        // Total distinct characters
        int distinct = 0;

        for (char ch : s) {
            if (freq[ch] == 0)
                distinct++;
            freq[ch]++;
        }

        // Reset frequency for sliding window
        fill(freq.begin(), freq.end(), 0);

        int left = 0;
        int count = 0;
        int ans = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] == 0)
                count++;

            freq[s[right]]++;

            // Window contains all distinct characters
            while (count == distinct) {
                ans = min(ans, right - left + 1);

                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    count--;

                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "AABBBCBBAC";
    string s2 = "aaab";

    cout << "Smallest window for \"" << s1 << "\": " << sol.findSubString(s1) << endl; // Output: 3 ("BAC")
    cout << "Smallest window for \"" << s2 << "\": " << sol.findSubString(s2) << endl; // Output: 2 ("ab")

    return 0;
}
