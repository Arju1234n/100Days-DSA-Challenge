/*
Problem Name: Container With Most Water
Platform: LeetCode
Difficulty: Medium

Approach 1: Brute Force calculating area for every pair of lines (O(n^2) time).
Approach 2: Two pointers starting at both ends, moving the pointer pointing to the shorter line inward.
Optimal Approach: Two pointers starting at both ends.

Time Complexity: O(n)
Space Complexity: O(1)

Pattern: Two Pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int width = right - left;
            int h = std::min(height[left], height[right]);
            int current_area = width * h;
            max_area = std::max(max_area, current_area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_area;
    }
};

int main() {
    Solution sol;
    std::vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(sol.maxArea(height1) == 49);
    std::cout << "Container With Most Water C++: All tests passed! 🎉" << std::endl;
    return 0;
}
