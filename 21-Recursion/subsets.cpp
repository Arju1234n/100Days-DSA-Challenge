/*
Problem Name: Subsets (Power Set)
Platform: LeetCode #78
Difficulty: Medium

Approach: Recursion (Take / Don't Take)
  At every index we have two choices:
    1. TAKE   — include arr[index] in current subset, recurse with index+1
    2. DON'T TAKE — skip arr[index], recurse with index+1
  Base Case: when index == arr.size(), the current subset is complete → store it.

  Total subsets = 2^N  (each element is either in or out)

Time Complexity : O(2^N * N) — 2^N subsets, each of average length N/2
Space Complexity: O(N)       — recursion depth + temp vector
Pattern: Recursion / Backtracking
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> ans;  // Final answer
    std::vector<int> temp;              // Current subset being built

    void solve(int index, std::vector<int>& arr) {
        // Base Case: processed all elements → record current subset
        if (index == (int)arr.size()) {
            ans.push_back(temp);
            return;
        }

        // ── TAKE arr[index] ─────────────────────────────────────
        temp.push_back(arr[index]);
        solve(index + 1, arr);

        // Undo (backtrack)
        temp.pop_back();

        // ── DON'T TAKE arr[index] ────────────────────────────────
        solve(index + 1, arr);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& arr) {
        ans.clear();
        temp.clear();
        solve(0, arr);
        return ans;
    }
};

// Helper: sort each subset and the outer list for comparison
std::vector<std::vector<int>> normalize(std::vector<std::vector<int>> v) {
    for (auto& s : v) std::sort(s.begin(), s.end());
    std::sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution sol;

    // ── Test 1: [1, 2, 3] → 8 subsets ───────────────────────────
    {
        std::vector<int> arr = {1, 2, 3};
        auto result = sol.subsets(arr);
        assert(result.size() == 8);

        std::vector<std::vector<int>> expected = {
            {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}
        };
        assert(normalize(result) == normalize(expected));
        std::cout << "Test 1 passed: [1,2,3] → " << result.size() << " subsets\n";
    }

    // ── Test 2: [0] → 2 subsets ──────────────────────────────────
    {
        std::vector<int> arr = {0};
        auto result = sol.subsets(arr);
        assert(result.size() == 2);
        std::cout << "Test 2 passed: [0] → " << result.size() << " subsets\n";
    }

    // ── Test 3: [] → 1 subset (empty set) ────────────────────────
    {
        std::vector<int> arr = {};
        auto result = sol.subsets(arr);
        assert(result.size() == 1);
        std::cout << "Test 3 passed: [] → " << result.size() << " subset\n";
    }

    // ── Print all subsets of [1,2,3] ─────────────────────────────
    {
        std::vector<int> arr = {1, 2, 3};
        auto result = sol.subsets(arr);
        auto sorted = normalize(result);

        std::cout << "\nAll subsets of [1,2,3]:\n";
        for (auto& subset : sorted) {
            std::cout << "  [";
            for (int i = 0; i < (int)subset.size(); ++i) {
                if (i) std::cout << ",";
                std::cout << subset[i];
            }
            std::cout << "]\n";
        }
    }

    std::cout << "\nSubsets C++: All tests passed! 🎉" << std::endl;
    return 0;
}
