#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string &s) {
        vector<bool> seen(26, false);
        string ans = "";

        for (char ch : s) {
            if (!seen[ch - 'a']) {
                ans += ch;
                seen[ch - 'a'] = true;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "zvvo";
    string s2 = "gfg";
    cout << sol.removeDuplicates(s1) << endl; // Output: "zvo"
    cout << sol.removeDuplicates(s2) << endl; // Output: "gf"
    return 0;
}
