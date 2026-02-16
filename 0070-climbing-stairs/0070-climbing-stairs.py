class Solution:
    def climbStairs(self, n: int) -> int:
        s_prev = 1 # ways to get 0
        s_now  = 1 # ways to get 1
        for k in range(2,n+1):
            s_next = s_prev + s_now # ways to get k
            s_prev = s_now
            s_now = s_next
        return s_now