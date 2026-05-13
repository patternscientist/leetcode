class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low, mid, high = 0, 0, len(nums)-1
        while mid <= high:
            if nums[mid] == 0:
                tmp = nums[low]
                nums[low] = nums[mid]
                nums[mid] = tmp
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                tmp = nums[high]
                nums[high] = nums[mid]
                nums[mid] = tmp
                high -= 1