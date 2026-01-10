class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        end  = nums[0]
        best = nums[0]
        for i in range(1,len(nums)):
            end  = max(nums[i], nums[i] + end)
            best = max(best, end)
        return best

