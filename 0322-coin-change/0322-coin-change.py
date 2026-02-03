class Solution:
    def solve(self, coins: List[int], amt: int, memo: List[int]) -> int:
        if amt < 0:         return -1
        if amt == 0:        return 0
        if memo[amt] != -2: return memo[amt]
        best = amt + 1
        for denom in coins:
            sub = self.solve(coins,amt-denom,memo)
            if sub >= 0: 
                best = min(best,sub+1)  
            if denom <= amt:
                memo[amt-denom] = sub
        return -1 if best == amt + 1 else best

    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [-2]*(amount+1)
        memo[0] = 0
        return self.solve(coins,amount,memo)