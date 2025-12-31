class Solution:
    def isPalindrome(self, s: str) -> bool:
        # string preprocessing:
        s = s.upper() # turn all letters uppercase
        s = ''.join(c for c in s if c.isalnum()) # and remove non-alphanumeric chars

        n = len(s)
        # two pointers 
        i = 0
        j = n-1

        # Invariant: all characters strictly outside [i, j] have been checked and matched; 
        # i.e. s[0..i-1] mirrors s[j+1..n-1].
        while (i < j):
            if (s[i] != s[j]):
                return False
            i += 1
            j -= 1
        
        return True