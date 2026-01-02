class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): 
            return False
            
        cnt = [0]*26
        for i in range(len(s)):
            cnt[ord('a') - ord(s[i])] += 1
            cnt[ord('a') - ord(t[i])] -= 1

        return all(x == 0 for x in cnt)

        
