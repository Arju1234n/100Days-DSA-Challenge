/*
Problem Name: Union of Two Sorted Arrays
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Insert every element of both arrays into a set and copy it out sorted, O((n + m) log(n + m)).
Approach 2: Concatenate both arrays, sort the result and remove consecutive duplicates.
Optimal Approach: Merge with two pointers, advancing the pointer at the smaller value (both on a tie)
and appending a value only when it differs from the last element already pushed.

Time Complexity: O(n + m)
Space Complexity: O(n + m) for the output

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    std::vector<int> findUnion(std::vector<int>& a, std::vector<int>& b) {
        std::vector<int> result;
        size_t i = 0;
        size_t j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                ++i;
            } else if (a[i] > b[j]) {
                if (result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                ++j;
            } else {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                ++i;
                ++j;
            }
        }

        while (i < a.size()) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            ++i;
        }

        while (j < b.size()) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            ++j;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: overlapping values in both arrays
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    std::vector<int> b1 = {1, 2, 3, 6, 7};
    std::vector<int> expected1 = {1, 2, 3, 4, 5, 6, 7};
    assert(sol.findUnion(a1, b1) == expected1);

    // Test Case 2: duplicates inside each array
    std::vector<int> a2 = {2, 2, 3, 4, 5};
    std::vector<int> b2 = {1, 1, 2, 3, 4};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    assert(sol.findUnion(a2, b2) == expected2);

    // Test Case 3: one array empty
    std::vector<int> a3 = {};
    std::vector<int> b3 = {5, 5, 8};
    std::vector<int> expected3 = {5, 8};
    assert(sol.findUnion(a3, b3) == expected3);

    // Test Case 4: disjoint ranges
    std::vector<int> a4 = {1, 2, 3};
    std::vector<int> b4 = {4, 5, 6};
    std::vector<int> expected4 = {1, 2, 3, 4, 5, 6};
    assert(sol.findUnion(a4, b4) == expected4);

    std::cout << "Union of Two Sorted Arrays C++: All tests passed! 🎉" << std::endl;
    return 0;
}
