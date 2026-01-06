class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n = len(s)
        if len(t) != n: return False

        cnt = [0]*26
        for i in range(n):
            cnt[ord(s[i]) - ord('a')] += 1
            cnt[ord(t[i]) - ord('a')] -= 1
        
        return all(x == 0 for x in cnt)