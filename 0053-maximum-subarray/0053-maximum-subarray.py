class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end  = nums[0]
        best = nums[0]
        for i in range(1,len(nums)):
            end  = max(nums[i], nums[i] + end)
            best = max(best, end)
        return best