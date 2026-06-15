class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l = 0
        r = n-1
        leftMax = 0
        rightMax = 0
        ans = 0
        while l < r:
            leftMax  = max(leftMax,height[l])
            rightMax = max(rightMax,height[r])
            if leftMax <= rightMax:
                ans += leftMax - height[l]
                l += 1
            else:
                ans += rightMax - height[r]
                r -= 1
        return ans