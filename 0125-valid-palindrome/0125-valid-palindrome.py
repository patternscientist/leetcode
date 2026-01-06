class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        i = 0
        j = n-1
        while i<j:
            while i<j and not s[i].isalnum(): i+=1
            while i<j and not s[j].isalnum(): j-=1
            if s[i].lower() != s[j].lower(): return False # be case-insensitive
            i+=1
            j-=1
        return True
        