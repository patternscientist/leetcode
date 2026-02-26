class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals,
                           key=lambda interval: interval[0])
        ans = []
        for interval in intervals:
            if len(ans) == 0 or ans[-1][1] < interval[0]:
                ans.append(interval)
            elif ans[-1][1] < interval[1]:
                ans[-1][1] = interval[1]
        return ans
