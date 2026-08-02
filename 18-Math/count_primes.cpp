/*
Problem Name: Count Primes
Platform: LeetCode
Difficulty: Medium

Approach: Sieve of Eratosthenes
1. Create a boolean vector `prime` of size `n` initialized to `true`.
2. Set `prime[0]` and `prime[1]` to `false`.
3. Loop `i` from 2 up to `sqrt(n)`. If `prime[i]` is true, mark all multiples starting from `i * i` up to `n` as `false`.
4. Count all indices from 2 to `n - 1` that remain `true`.

Time Complexity: O(n log log n)
Space Complexity: O(n)

Pattern: Math / Sieve of Eratosthenes
*/

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        std::vector<bool> prime(n, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i])
                count++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1: n = 10 (Primes strictly less than 10 are 2, 3, 5, 7 -> count = 4)
    assert(sol.countPrimes(10) == 4);

    // Test Case 2: n = 0
    assert(sol.countPrimes(0) == 0);

    // Test Case 3: n = 1
    assert(sol.countPrimes(1) == 0);

    // Test Case 4: n = 2
    assert(sol.countPrimes(2) == 0);

    // Test Case 5: n = 5 (Primes: 2, 3 -> count = 2)
    assert(sol.countPrimes(5) == 2);

    std::cout << "Count Primes C++: All tests passed! 🎉" << std::endl;
    return 0;
}
