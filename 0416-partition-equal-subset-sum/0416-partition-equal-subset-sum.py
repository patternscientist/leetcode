class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        target = total // 2
        if total % 2 != 0:
            return False
        print("target:",target)
        dp = [False] * (target + 1)
        dp[0] = True
        for x in nums:
            for s in range(target,x-1,-1):
                dp[s] = dp[s] or dp[s-x]
                if s == 11:
                    print("now:",dp[s])
        return dp[target]