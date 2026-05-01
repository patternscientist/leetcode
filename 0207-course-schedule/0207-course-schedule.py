class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for p in prerequisites:
            a,b = p
            adj[b].append(a)
            indeg[a] += 1
        q = deque()
        for course in range(numCourses):
            if indeg[course] == 0:
                q.append(course)
        taken = 0
        while len(q) != 0:
            cur = q.popleft()
            taken += 1
            for neighbor in adj[cur]:
                indeg[neighbor] -= 1
                if indeg[neighbor] == 0:
                    q.append(neighbor)
        return taken == numCourses