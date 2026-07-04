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
    
    // Test Case 1
    std::vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(sol.maxArea(height1) == 49);
    
    // Test Case 2
    std::vector<int> height2 = {1, 1};
    assert(sol.maxArea(height2) == 1);
    
    std::cout << "Day 4 (Container With Most Water) C++: All tests passed successfully! 🎉" << std::endl;
    return 0;
}
