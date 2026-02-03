class Solution:
    def solve(self, coins: List[int], amt: int, memo: List[int]):
        if amt < 0:         return -1
        if amt == 0:        return 0
        if memo[amt] != -2: return memo[amt]
        for denom in coins:
            if amt == denom:
                return 1
        best = amt+1
        for denom in coins:
            sub = self.solve(coins,amt-denom,memo)
            if sub >= 0: best = min(best,sub+1)
        memo[amt] = -1 if best == amt+1 else best
        return memo[amt]

    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = [-2]*(amount + 1)
        return self.solve(coins,amount,memo)