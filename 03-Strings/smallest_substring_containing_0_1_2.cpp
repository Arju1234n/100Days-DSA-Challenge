#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int smallestSubstring(string &s) {
        int n = s.size();
        int count[3] = {0, 0, 0};
        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            count[s[right] - '0']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans = min(ans, right - left + 1);
                count[s[left] - '0']--;
                left++;
            }
        }

        if (ans == INT_MAX)
            return -1; // GFG return convention for impossible case

        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "01212";
    string s2 = "10212";
    string s3 = "1111";

    cout << sol.smallestSubstring(s1) << endl; // Output: 3 ("012")
    cout << sol.smallestSubstring(s2) << endl; // Output: 3 ("102")
    cout << sol.smallestSubstring(s3) << endl; // Output: -1

    return 0;
}
