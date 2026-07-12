/*
Problem Name: Trapping Rain Water
Platform: LeetCode
Difficulty: Hard

Approach 1: Dynamic Programming / Prefix & Suffix max arrays (O(n) time, O(n) space).
Approach 2: Using Stack (O(n) time, O(n) space).
Optimal Approach: Two pointers moving inwards tracking left and right max heights.

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
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;
    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(sol.trap(height1) == 6);

    std::vector<int> height2 = {4, 2, 0, 3, 2, 5};
    assert(sol.trap(height2) == 9);

    std::cout << "Trapping Rain Water C++: All tests passed! 🎉" << std::endl;
    return 0;
}
