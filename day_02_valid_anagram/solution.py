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

# Simple Verification Tests
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1
    assert sol.isAnagram("anagram", "nagaram") is True
    
    # Test Case 2
    assert sol.isAnagram("rat", "car") is False
    
    # Test Case 3
    assert sol.isAnagram("a", "ab") is False
    
    print("Day 2 (Valid Anagram): All tests passed successfully! 🎉")
