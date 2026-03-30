class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best          = nums[0]
        bestEndingAtI = nums[0]
        n             = len(nums)
        for i in range(1,n):
            bestEndingAtI = max(bestEndingAtI+nums[i],nums[i])
            best          = max(best,bestEndingAtI)
        return best