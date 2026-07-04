# """
# Problem Name: Valid Anagram
# Platform: LeetCode
# Difficulty: Easy
#
# Approach 1: Sort strings s and t and check equality. O(n log n) time.
# Approach 2: Hash map tracking characters frequency of s and subtracting for t.
# Optimal Approach: Hash map frequency table check.
#
# Time Complexity: O(n)
# Space Complexity: O(1) - since character space is fixed at 26
#
# Pattern: Hashing / Frequency Map
# """

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        char_counts = {}
        for char in s:
            char_counts[char] = char_counts.get(char, 0) + 1
            
        for char in t:
            if char not in char_counts:
                return False
            char_counts[char] -= 1
            if char_counts[char] == 0:
                del char_counts[char]
                
        return len(char_counts) == 0

if __name__ == "__main__":
    sol = Solution()
    assert sol.isAnagram("anagram", "nagaram") is True
    assert sol.isAnagram("rat", "car") is False
    print("Valid Anagram Python: All tests passed! 🎉")
