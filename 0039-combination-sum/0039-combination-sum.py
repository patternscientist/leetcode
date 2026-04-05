class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        ans  = []
        n    = len(candidates)
        def dfs(candidates: List[int], start: int, remaining: int) -> None:
            if remaining == 0:
                ans.append(path.copy())
            for i in range(start,n):
                candidate = candidates[i]
                if candidate > remaining:
                    break
                path.append(candidate)
                dfs(candidates,i,remaining-candidate)
                path.remove(candidate)
            return 
        candidates = sorted(candidates)
        dfs(candidates,0,target)
        return ans