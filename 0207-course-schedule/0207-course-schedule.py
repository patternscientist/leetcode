class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for p in prerequisites:
            a,b = p
            adj[b].append(a)
            indeg[a] += 1
        q = deque()
        for c in range(numCourses):
            if indeg[c] == 0:
                q.append(c)
        taken = 0
        while len(q) != 0:
            cur = q.popleft()
            taken += 1
            for other in adj[cur]:
                indeg[other] -= 1
                if indeg[other] == 0:
                    q.append(other)
        return taken == numCourses