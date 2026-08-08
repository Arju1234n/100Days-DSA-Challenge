#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(string& s, int left, int right, int k) {
        if (right - left + 1 < k)
            return 0;

        vector<int> freq(26, 0);

        // Frequency count
        for (int i = left; i <= right; i++) {
            freq[s[i] - 'a']++;
        }

        // Find a bad character (frequency < k)
        for (int i = left; i <= right; i++) {
            if (freq[s[i] - 'a'] < k) {
                int next = i + 1;

                while (next <= right && freq[s[next] - 'a'] < k) {
                    next++;
                }

                return max(
                    solve(s, left, i - 1, k),
                    solve(s, next, right, k)
                );
            }
        }

        // Every character occurs >= k times
        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};

int main() {
    Solution sol;
    cout << sol.longestSubstring("aaabb", 3) << endl;  // Output: 3 ("aaa")
    cout << sol.longestSubstring("ababbc", 2) << endl; // Output: 5 ("ababb")
    return 0;
}
