#include <iostream>
#include <string>

using namespace std;

// Problem Name: Excel Sheet Column Number
// Platform: LeetCode 171
// Difficulty: Easy
// Time Complexity: O(N) where N is the length of columnTitle
// Space Complexity: O(1) auxiliary space

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for (char ch : columnTitle) {
            int value = ch - 'A' + 1;
            ans = ans * 26 + value;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout << "A -> " << sol.titleToNumber("A") << endl;     // 1
    cout << "AB -> " << sol.titleToNumber("AB") << endl;   // 28
    cout << "ZY -> " << sol.titleToNumber("ZY") << endl;   // 701
    return 0;
}
