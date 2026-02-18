class Solution:
    ans  = []
    path = []
    used = []
    def dfs(self,nums):
        if len(self.path) == len(nums):
            self.ans.append(self.path[::])
            return 
        for i in range(0,len(nums)):
            if self.used[i]:
                continue 
            self.used[i] += 1
            x = nums[i]
            self.path.append(x)
            self.dfs(nums)
            self.path.remove(x)
            self.used[i] -= 1

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans = []
        self.used = [0] * len(nums)
        self.dfs(nums)
        return self.ans