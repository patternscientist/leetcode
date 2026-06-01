class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        maxLen = max(len(w) for w in wordDict)
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        for i in range(1,n+1):
            for length in range(1,min(i,maxLen)+1):
                j = i-length
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break
        return dp[n]