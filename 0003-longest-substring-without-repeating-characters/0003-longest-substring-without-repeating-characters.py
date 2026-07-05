class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen  = [-1] * 256 
        start = 0
        best  = 0
        for i,ch in enumerate(s):
            if seen[ord(ch)] != -1:
                start = max(start,seen[ord(ch)]+1)
            best = max(best,i-start+1)
            seen[ord(ch)] = i
        return best
