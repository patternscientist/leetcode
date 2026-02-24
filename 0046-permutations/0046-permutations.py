class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n    = len(nums)
        ans  = []
        path = []
        used = [False] * n
        def dfs() -> None:
            if len(path) == n:
                ans.append(path[::])
            for i in range(n):
                if used[i]:
                    continue
                x       = nums[i]
                used[i] = True
                path.append(x)
                dfs()
                path.remove(x)
                used[i] = False
        dfs()
        return ans
