class Solution:
    def isPalindrome(self, s: str) -> bool:
        # string preprocessing:
        s = s.upper() # turn all letters uppercase
        s = ''.join(c for c in s if c.isalnum()) # and remove non-alphanumeric chars

        n = len(s)
        # two pointers 
        i = 0
        j = n-1

        # invariant after iteration k: 
        #     s[:k+1] == s[n-k-1:]
        while (i < j):
            if (s[i] != s[j]):
                return False
            i += 1
            j -= 1
        
        return True