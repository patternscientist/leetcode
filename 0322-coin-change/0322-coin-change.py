class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = amount+1
        dp = [INF]*(amount+1)
        dp[0] = 0
        for k in range(1,amount+1):
            for denom in coins:
                if k - denom >= 0:
                    dp[k] = min(dp[k],dp[k-denom]+1)
        return -1 if dp[amount] == INF else dp[amount]