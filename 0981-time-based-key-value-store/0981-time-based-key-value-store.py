class TimeMap:

    def __init__(self):
        self.mp = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.mp:
            self.mp[key] = []
        self.mp[key].append((value,timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.mp:
            return ""
        lst = self.mp[key]
        l   = 0
        r   = len(lst)-1
        idx = -1
        while l <= r:
            mid = (l+r)//2
            if lst[mid][1] <= timestamp:
                l   = mid+1
                idx = mid
            else:
                r = mid-1
        return "" if idx == -1 else lst[idx][0]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)