class Solution:
    def climbStairs(self, n: int) -> int:
        dp = deque(maxlen=2)
        dp.append(1)
        dp.append(1)
        for _ in range(2,n+1):
            dp.append(dp[0]+dp[1])
        return dp[-1]