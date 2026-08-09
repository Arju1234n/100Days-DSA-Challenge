#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int flip1 = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Check matching against pattern starting with '0'
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                flip1++;
            }
        }

        // flip2 is guaranteed to be (n - flip1)
        return min(flip1, n - flip1);
    }
};

int main() {
    Solution sol;
    string s1 = "001";
    string s2 = "0001010111";
    cout << sol.minFlips(s1) << endl; // Output: 1
    cout << sol.minFlips(s2) << endl; // Output: 2
    return 0;
}
