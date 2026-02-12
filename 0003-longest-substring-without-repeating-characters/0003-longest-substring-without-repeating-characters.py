class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        best  = 0
        seen  = [-1]*256
        for i,ch in enumerate(s):
            if seen[ord(ch)] != -1:
                start = max(start, seen[ord(ch)]+1)
            best = max(best, i-start+1)
            seen[ord(ch)] = i
        return best
            