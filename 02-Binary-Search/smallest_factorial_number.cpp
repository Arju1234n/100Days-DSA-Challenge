/*
Problem Name: Smallest number with at least n trailing zeroes in factorial
Platform: GeeksforGeeks (Smallest Factorial Number)
Difficulty: Medium

Approach 1: Brute Force / Linear Search. Check factorials of numbers 5, 10, 15... until trailing zeroes >= n.
Time Complexity: O(n * log5(n)).

Optimal Approach: Binary Search on Answer.
The number of trailing zeroes in m! is calculated using Legendre's Formula:
count = floor(m / 5) + floor(m / 25) + floor(m / 125) + ...
Since the count of trailing zeroes is a non-decreasing monotonic function of m, we can perform binary search in range [0, 5 * n].
If count >= n for mid, mid is a valid candidate; try smaller values by setting high = mid - 1.
Otherwise, search higher numbers by setting low = mid + 1.

Time Complexity: O(log(5n) * log5(5n)) = O(log n)
Space Complexity: O(1) auxiliary space

Pattern: Binary Search on Answer
*/

#include <iostream>
#include <cassert>

class Solution {
private:
    // Helper function to count trailing zeroes in m!
    long long countTrailingZeroes(long long m) {
        long long count = 0;
        while (m >= 5) {
            count += m / 5;
            m /= 5;
        }
        return count;
    }

public:
    int findNum(int n) {
        if (n <= 0) return 0;

        long long low = 0;
        long long high = 5LL * n;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countTrailingZeroes(mid) >= n) {
                ans = mid;
                high = mid - 1; // Try to find a smaller number
            } else {
                low = mid + 1;  // Search in upper half
            }
        }

        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 0 trailing zeroes
    assert(sol.findNum(0) == 0);

    // Test Case 2: n = 1 trailing zero (5! = 120 -> 1 zero)
    assert(sol.findNum(1) == 5);

    // Test Case 3: n = 2 trailing zeroes (10! = 3628800 -> 2 zeroes)
    assert(sol.findNum(2) == 10);

    // Test Case 4: n = 5 trailing zeroes (24! has 4, 25! has 6 >= 5 zeroes)
    assert(sol.findNum(5) == 25);

    // Test Case 5: n = 6 trailing zeroes (25! has 6 zeroes)
    assert(sol.findNum(6) == 25);

    // Test Case 6: n = 10 trailing zeroes (45/5 = 9, 45/25 = 1 => 9+1 = 10)
    assert(sol.findNum(10) == 45);

    // Test Case 7: n = 100 trailing zeroes (405/5 = 81, 405/25 = 16, 405/125 = 3 => 81+16+3 = 100)
    assert(sol.findNum(100) == 405);

    std::cout << "Smallest Factorial Number Binary Search C++: All tests passed! 🎉" << std::endl;
    return 0;
}
