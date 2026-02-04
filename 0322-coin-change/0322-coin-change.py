class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = amount + 1
        dp = [INF]*(amount + 1) 
        dp[0] = 0
        for n in range(1,amount+1):
            for denom in coins:
                if denom <= n: 
                    dp[n] = min(dp[n],dp[n-denom]+1)
        return dp[amount] if dp[amount] != INF else -1