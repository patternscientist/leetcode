class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        best = 0
        bestStart = 0
        def expand(l,r,best,bestStart):
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            length = r-l-1
            if length > best:
                best      = length
                bestStart = l+1
            return (best,bestStart)
        for i in range(n):
            (best,bestStart) = expand(i,i,best,bestStart)
            (best,bestStart) = expand(i,i+1,best,bestStart)
        return s[bestStart:bestStart+best]