class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
       dist = lambda point: (point[0]**2 + point[1]**2)**0.5
       points.sort(key=dist)
       return points[:k]