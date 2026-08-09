#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Problem Name: Excel Sheet Column Title / Column Name From Given Number
// Platform: LeetCode 168 / GeeksforGeeks
// Difficulty: Easy
// Time Complexity: O(log26(N))
// Space Complexity: O(1) auxiliary space

class Solution {
public:
    string colName(int n) {
        string ans = "";

        while (n > 0) {
            n--;
            char ch = 'A' + (n % 26);
            ans += ch;
            n /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    cout << "1 -> " << sol.colName(1) << endl;     // A
    cout << "28 -> " << sol.colName(28) << endl;   // AB
    cout << "701 -> " << sol.colName(701) << endl; // ZY
    return 0;
}
