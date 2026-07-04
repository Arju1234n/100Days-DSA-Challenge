# """
# Problem Name: Valid Palindrome
# Platform: LeetCode
# Difficulty: Easy
#
# Approach 1: Filter alphanumeric characters, convert to lowercase, reverse string and check equality. O(n) space.
# Approach 2: Two pointers moving inwards comparing lowercase alphanumeric characters in-place.
# Optimal Approach: Two pointers in-place.
#
# Time Complexity: O(n)
# Space Complexity: O(1)
#
# Pattern: Two Pointers
# """

class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        
        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
                
            if s[left].lower() != s[right].lower():
                return False
                
            left += 1
            right -= 1
            
        return True

if __name__ == "__main__":
    sol = Solution()
    assert sol.isPalindrome("A man, a plan, a canal: Panama") is True
    assert sol.isPalindrome("race a car") is False
    print("Valid Palindrome Python: All tests passed! 🎉")
