class TimeMap:

    def __init__(self):
        self.mp = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.mp:
            self.mp[key] = []
        self.mp[key].append((timestamp,value))

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.mp:
            return ""
        lst = self.mp[key]
        k = len(lst)
        l,r = 0,k-1
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if lst[mid][0] <= timestamp:
                ans = mid
                l   = mid + 1
            else:
                r   = mid - 1
        return "" if ans == -1 else lst[ans][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)