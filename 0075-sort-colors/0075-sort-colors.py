class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n    = len(nums)
        low  = 0
        mid  = 0
        high = n-1
        while mid <= high:
            if nums[mid] == 0:
                tmp       = nums[mid]
                nums[mid] = nums[low]
                nums[low] = tmp
                low      += 1
                mid      += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                tmp        = nums[mid]
                nums[mid]  = nums[high]
                nums[high] = tmp
                high      -= 1