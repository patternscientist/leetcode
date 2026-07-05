class MedianFinder:

    def __init__(self):
        self.lo = []
        self.hi = []

    def addNum(self, num: int) -> None:
        if len(self.lo) == 0 or num <= self.lo[0]:
            heappush_max(self.lo,num)
        else:
            heappush(self.hi,num)
        
        if len(self.lo) > len(self.hi) + 1:
            heappush(self.hi, heappop_max(self.lo))
        elif len(self.lo) < len(self.hi):
            heappush_max(self.lo, heappop(self.hi))


    def findMedian(self) -> float:
        if len(self.lo) > len(self.hi):
            return self.lo[0]
        return (self.lo[0] + self.hi[0]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()