class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = nums[0]
        prefixBest = nums[0]
        for num in nums[1:]:
            prefixBest = max(prefixBest+num,num)
            best = max(best,prefixBest)
        return best
