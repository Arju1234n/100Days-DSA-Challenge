/*
Problem Name: Check if two arrays are equal or not
Platform: GeeksForGeeks
Difficulty: Easy

Approach 1: Sorting. Sort both arrays and compare them.
Time Complexity: O(n log n)
Space Complexity: O(1) (excluding sort stack space), but it modifies the inputs.

Approach 2: Hashing. Use a frequency map (unordered_map) to count elements.
Time Complexity: O(n)
Space Complexity: O(n)

Pattern: Frequency Counter
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

class Solution {
public:
    // Optimal Approach: Hashing
    bool checkEqual(const std::vector<int>& a, const std::vector<int>& b) {
        if (a.size() != b.size()) {
            return false;
        }
        std::unordered_map<int, int> count;
        for (int num : a) {
            count[num]++;
        }
        for (int num : b) {
            if (count.find(num) == count.end() || count[num] == 0) {
                return false;
            }
            count[num]--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Equal arrays
    std::vector<int> a1 = {1, 2, 5, 4, 0};
    std::vector<int> b1 = {2, 4, 5, 0, 1};
    assert(sol.checkEqual(a1, b1) == true);

    // Test Case 2: Not equal (different elements)
    std::vector<int> a2 = {1, 2, 5};
    std::vector<int> b2 = {2, 4, 15};
    assert(sol.checkEqual(a2, b2) == false);

    // Test Case 3: Not equal (different sizes)
    std::vector<int> a3 = {1, 2, 3};
    std::vector<int> b3 = {1, 2};
    assert(sol.checkEqual(a3, b3) == false);

    // Test Case 4: Equal with duplicate elements
    std::vector<int> a4 = {1, 2, 2, 3};
    std::vector<int> b4 = {2, 3, 1, 2};
    assert(sol.checkEqual(a4, b4) == true);

    std::cout << "Check Equal Arrays C++: All tests passed! 🎉" << std::endl;
    return 0;
}
