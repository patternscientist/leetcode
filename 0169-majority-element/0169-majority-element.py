class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 1
        cur = nums[0]
        for num in nums[1:]:
            if num == cur:
                cnt += 1
            else:
                cnt -= 1
                if cnt < 0:
                    cnt = 1
                    cur = num
        return cur