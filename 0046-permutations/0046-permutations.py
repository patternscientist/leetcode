class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(nums,used):
            if all(used):
                ans.append(path.copy())
                return
            for i,num in enumerate(nums):
                if used[i]:
                    continue
                used[i] = True 
                path.append(num)
                dfs(nums,used)
                path.remove(num)
                used[i] = False
            return
        path = []
        ans  = []
        n = len(nums)
        used = [False]*n
        dfs(nums,used)
        return ans