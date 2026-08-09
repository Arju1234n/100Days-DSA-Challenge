#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Name: Remove and Reverse
// Platform: GeeksforGeeks
// Difficulty: Medium
// 
// Optimal Approach: Two-Pointer / Frequency Array (O(N) time, O(1) auxiliary space)
// We maintain character frequencies and two pointers (left & right).
// Instead of physically reversing the string on every removal (which causes O(N^2) complexity),
// we track the current reading direction (forward vs backward).

class Solution {
public:
    string removeReverse(string S) {
        int n = S.size();
        vector<int> freq(26, 0);

        for (char ch : S) {
            freq[ch - 'a']++;
        }

        int left = 0, right = n - 1;
        bool dirForward = true; // true = left to right, false = right to left
        vector<bool> removed(n, false);

        while (left <= right) {
            if (dirForward) {
                if (freq[S[left] - 'a'] > 1) {
                    freq[S[left] - 'a']--;
                    removed[left] = true;
                    dirForward = !dirForward; // Reverse direction
                }
                left++;
            } else {
                if (freq[S[right] - 'a'] > 1) {
                    freq[S[right] - 'a']--;
                    removed[right] = true;
                    dirForward = !dirForward; // Reverse direction
                }
                right--;
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                ans += S[i];
            }
        }

        if (!dirForward) {
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "abab";
    string s2 = "dddd";

    cout << "s1: " << sol.removeReverse(s1) << endl; // Output: "ba"
    cout << "s2: " << sol.removeReverse(s2) << endl; // Output: "d"

    return 0;
}
