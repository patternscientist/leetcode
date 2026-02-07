class Solution:
    def longestPalindrome(self, s: str) -> int:
        seen = [0]*256
        for c in s:
            seen[ord(c)] += 1
        ans = 0
        hasCenter = False
        for n in seen:
            ans += (n // 2) * 2
            if n % 2 == 1:
                hasCenter = True
        if hasCenter: 
            ans += 1
        return ans