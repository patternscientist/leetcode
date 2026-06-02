class Solution:
    def longestPalindrome(self, s: str) -> str:
        n         = len(s)
        bestStart = 0
        bestLen   = 1

        def expand(l: int, r: int, bestStart: int, bestLen: int) -> (int,int):
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            start  = l+1
            length = r-l-1
            if length > bestLen:
                bestStart = start
                bestLen = length
            return (bestStart,bestLen)
            
        for i in range(n):
            bestStart, bestLen = expand(i,i,bestStart,bestLen)
            bestStart, bestLen = expand(i,i+1,bestStart,bestLen)
        
        return s[bestStart:bestStart+bestLen]