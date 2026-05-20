class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        count = [0] * 60
        for ch in s:
            count[ord(ch)-ord('a')] += 1
        hasOdd = False
        for x in count:
            ans += (x // 2) * 2
            if not hasOdd and x % 2 == 1:
                hasOdd = True
                ans += 1
        return ans
        