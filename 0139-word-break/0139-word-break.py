class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        maxLen  = 0
        for w in wordDict:
            maxLen = max(maxLen,len(w))
        n  = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1,n+1):
            for len_ in range(1,min(maxLen,i)+1):
                j = i - len_
                if dp[j] and s[j:j+len_] in wordSet:
                    dp[i] = True
                    break
        return dp[n]