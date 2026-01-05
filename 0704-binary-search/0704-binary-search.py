class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        l = 0
        r = n-1
        while l<=r:
            mid = (l+r)//2
            curr = nums[mid]
            if curr == target:  return mid
            elif curr < target: l = mid+1
            else: r = mid-1
        return -1