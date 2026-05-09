class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans  = []
        path = []
        n    = len(candidates)
        def dfs(candidates: List[int], n: int, start: int, remaining: int) -> None:
            if remaining == 0:
                ans.append(path.copy())
                return
            if remaining < 0:
                return 
            for i in range(start,n):
                path.append(candidates[i])
                dfs(candidates,n,i,remaining-candidates[i])
                path.remove(candidates[i])
            return
        dfs(candidates,n,0,target)
        return ans