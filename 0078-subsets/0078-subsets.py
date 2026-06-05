class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        path = []
        ans  = []
        def dfs(nums: List[int], start: int) -> None:
            ans.append(path[:])
            if start == n:
                return 
            for i in range(start,n):
                path.append(nums[i])
                dfs(nums,i+1)
                path.remove(nums[i])
        dfs(nums,0)
        return ans