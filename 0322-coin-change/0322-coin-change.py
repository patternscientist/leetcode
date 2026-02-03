class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        INF = amount + 1
        dp = [INF]*INF
        dp[0] = 0
        for n in range(1,amount+1):
            for denom in coins:
                if denom <= n:
                    dp[n] = min(dp[n],dp[n-denom]+1)
        return dp[amount] if dp[amount] != INF else -1
        