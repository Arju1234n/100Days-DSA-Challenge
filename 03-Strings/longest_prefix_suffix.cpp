#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Problem Name: Longest Prefix Suffix (LPS)
// Platform: GeeksforGeeks / KMP Pre-processing
// Difficulty: Hard / Medium
// Time Complexity: O(N)
// Space Complexity: O(N) for LPS table

class Solution {
public:
    int lps(string s) {
        int n = s.size();
        vector<int> lpsTable(n, 0);

        int len = 0; // length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lpsTable[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lpsTable[len - 1];
                } else {
                    lpsTable[i] = 0;
                    i++;
                }
            }
        }

        return lpsTable[n - 1];
    }
};

int main() {
    Solution sol;
    string s1 = "abab";
    string s2 = "aaaa";
    string s3 = "abcab";

    cout << "LPS for \"" << s1 << "\": " << sol.lps(s1) << endl; // Output: 2 ("ab")
    cout << "LPS for \"" << s2 << "\": " << sol.lps(s2) << endl; // Output: 3 ("aaa")
    cout << "LPS for \"" << s3 << "\": " << sol.lps(s3) << endl; // Output: 2 ("ab")

    return 0;
}
