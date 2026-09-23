class Solution:
    def trap(self, height: list[int]) -> int:
        l = 0
        r = len(height)-1
        lMax = height[l]
        rMax = height[r]
        ans  = 0
        while l < r:
            lHeight = height[l]
            rHeight = height[r]
            lMax = max(lMax,lHeight)
            rMax = max(rMax,rHeight)
            if lMax < rMax:
                ans += lMax - lHeight
                l += 1
            else:
                ans += rMax - rHeight
                r -= 1
        return ans