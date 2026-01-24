class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(magazine) < len(ransomNote):
            return False
        cnt = [0]*26
        for c in magazine:
            cnt[ord(c)-ord('a')] += 1
        for c in ransomNote:
            cnt[ord(c)-ord('a')] -= 1
            if cnt[ord(c)-ord('a')] < 0:
                return False
        return True