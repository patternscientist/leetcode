class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        bestLen = 0
        n = len(s)
        seen = [-1]*256
        for i in range(n):
            ch = s[i]
            if seen[ord(ch)] != -1:
                start = max(start,seen[ord(ch)]+1)
            bestLen = max(bestLen,i-start+1)
            seen[ord(ch)] = i
        return bestLen