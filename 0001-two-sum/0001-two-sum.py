class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i,num in enumerate(nums):
            need = target - num
            if need in mp:
                return [mp[need],i]
            mp[num] = i
        return []
        