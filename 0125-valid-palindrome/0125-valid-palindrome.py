class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.upper() 
        s = ''.join(c for c in s if c.isalnum())
        i = 0
        j = len(s)-1

        while (i < j):
            if (s[i] != s[j]):
                return False
            i += 1
            j -= 1
        
        return True