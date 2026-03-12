class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m,n = len(s),len(t)
        if m != n: return False
        count = [0] * 26
        for ch in s:
            count[ord(ch)-ord('a')] += 1
        for ch in t:
            count[ord(ch)-ord('a')] -= 1
            if count[ord(ch)-ord('a')] < 0:
                return False
        return True