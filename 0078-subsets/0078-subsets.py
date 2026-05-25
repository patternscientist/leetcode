class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n   = len(nums)
        def dfs(nums: List[int],start: int, subset: List[int]) -> None:
            ans.append(subset[:])
            if start == n:
                return 
            for i in range(start,n):
                subset.append(nums[i])
                dfs(nums,i+1,subset)
                subset.remove(nums[i])
        dfs(nums,0,[])
        return ans