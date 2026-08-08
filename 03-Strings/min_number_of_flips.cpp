#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int flip1 = 0;
        int flip2 = 0;

        for (int i = 0; i < s.size(); i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected1)
                flip1++;

            if (s[i] != expected2)
                flip2++;
        }

        return min(flip1, flip2);
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
