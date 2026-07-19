class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans  = []
        path = []
        def dfs(nums,n,used,numUsed):
            if numUsed == n:
                ans.append(path[:])
                return 
            for i,num in enumerate(nums):
                if used[i]:
                    continue
                path.append(num)
                used[i] = True
                dfs(nums,n,used,numUsed+1)
                path.remove(num)
                used[i] = False
        n    = len(nums)
        used = [False] * n
        dfs(nums,n,used,0)
        return ans
