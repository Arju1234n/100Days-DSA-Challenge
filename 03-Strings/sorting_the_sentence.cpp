/*
Problem Name: Sorting the Sentence
Platform: LeetCode
Difficulty: Easy

Approach 1: Word Parsing and Insertion.
We scan the sentence word by word. Each word ends with its original 1-based index (1 to 9).
We extract the index, remove it from the word, and store the word at that index in a vector of strings.
Finally, we reconstruct the sorted sentence by joining the non-empty words in the vector.

Time Complexity: O(N) where N is the length of the string `s`. We traverse the string once.
Space Complexity: O(N) to store the parsed words and the output string.

Pattern: String Parsing / Split and Join
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution {
public:
    std::string sortSentence(std::string s) {
        std::vector<std::string> words(10);
        std::string temp = "";

        for (size_t i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!temp.empty()) {
                    int pos = temp.back() - '0';   // Last character is position
                    temp.pop_back();               // Remove the digit
                    words[pos] = temp;
                    temp = "";
                }
            }
            else {
                temp += s[i];
            }
        }

        std::string ans = "";
        for (int i = 1; i < 10; i++) {
            if (words[i] != "") {
                if (!ans.empty())
                    ans += " ";
                ans += words[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "is2 sentence4 This1 a3" -> "This is a sentence"
    assert(sol.sortSentence("is2 sentence4 This1 a3") == "This is a sentence");

    // Test Case 2: "Myself2 Me1" -> "Me Myself"
    assert(sol.sortSentence("Myself2 Me1") == "Me Myself");

    std::cout << "Sorting the Sentence C++: All tests passed! 🎉" << std::endl;
    return 0;
}
