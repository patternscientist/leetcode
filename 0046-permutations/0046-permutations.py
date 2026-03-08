class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans  = []
        path = []
        n    = len(nums)
        used = [False] * n
        def dfs() -> None:
            if len(path) == n:
                ans.append(path.copy())
                return
            for i,num in enumerate(nums):
                if used[i]:
                    continue
                used[i] = True
                path.append(num)
                dfs()
                path.remove(num)
                used[i] = False
            return 
        dfs()
        return ans
