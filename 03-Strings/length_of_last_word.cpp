#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        int count = 0;

        // Count length of last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World") << endl;                  // Output: 5
    cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl; // Output: 4
    cout << sol.lengthOfLastWord("luffy is still joyboy") << endl;        // Output: 6
    return 0;
}
