class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        best = 0
        mp = {}
        for i in range(len(s)):
            c = s[i]
            if c in mp:
                start = max(start, mp[c]+1)
            best = max(best, i+1-start)
            mp[c] = i
        return best