/*
Problem Name: Valid Perfect Square
Platform: LeetCode (367. Valid Perfect Square)
Difficulty: Easy

Approach 1: Linear Search. Try numbers from 1 upwards, checking if i * i == num. Stop if i * i > num. Time Complexity: O(sqrt(num)).
Optimal Approach: Binary Search. Use binary search over the range [1, num].
Let low = 1, high = num.
While low <= high:
  mid = low + (high - low) / 2
  Using division to prevent overflow:
  If mid == num / mid and num % mid == 0, then mid * mid == num, return true.
  If mid < num / mid or (mid == num / mid and num % mid != 0), search in the right half (low = mid + 1).
  Otherwise, search in the left half (high = mid - 1).

Time Complexity: O(log num) worst and average case.
Space Complexity: O(1) auxiliary space.

Pattern: Binary Search on Search Space
*/

#include <iostream>
#include <cassert>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        
        int low = 1, high = num;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is the square root using division to prevent integer overflow
            if (mid == num / mid && num % mid == 0) {
                return true;
            } else if (mid < num / mid) {
                low = mid + 1; // Too small, search right
            } else {
                high = mid - 1; // Too large, search left
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: 16 (Perfect Square)
    assert(sol.isPerfectSquare(16) == true);

    // Test Case 2: 14 (Not a Perfect Square)
    assert(sol.isPerfectSquare(14) == false);

    // Test Case 3: 1 (Perfect Square)
    assert(sol.isPerfectSquare(1) == true);

    // Test Case 4: 0 (Not valid under constraint of positive integer, but handled safely)
    assert(sol.isPerfectSquare(0) == false);

    // Test Case 5: 2 (Not a Perfect Square)
    assert(sol.isPerfectSquare(2) == false);

    // Test Case 6: 2147483647 (Max signed 32-bit int, not a perfect square)
    assert(sol.isPerfectSquare(2147483647) == false);

    // Test Case 7: 2147395600 (46340 * 46340, large Perfect Square)
    assert(sol.isPerfectSquare(2147395600) == true);

    std::cout << "Valid Perfect Square C++: All tests passed! 🎉" << std::endl;
    return 0;
}
