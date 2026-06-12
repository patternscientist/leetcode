class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        wordSet = set(wordDict)
        maxLen = max(map(len, wordDict))
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1,n+1):
            for len_ in range(1,min(i,maxLen)+1):
                j=i-len_
                if dp[j] and s[j:j+len_] in wordSet:
                    dp[i] = True
                    break
        return dp[n]