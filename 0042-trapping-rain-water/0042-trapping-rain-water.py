class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l,r = 0,n-1
        leftMax,rightMax = 0,0
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