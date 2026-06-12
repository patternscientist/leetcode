class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        best  = 0
        start = 0
        seen  = [-1] * (256)
        for i,ch in enumerate(s):
            if (idx := seen[ord(ch)]) != -1:
                start = max(start,idx+1)
            best = max(best,i-start+1)
            seen[ord(ch)] = i
        return best