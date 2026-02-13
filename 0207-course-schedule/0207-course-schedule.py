class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0]*numCourses
        for preq in prerequisites:
            a,b = preq
            adj[b].append(a)
            indeg[a] += 1
        q = deque()
        for course,deg in enumerate(indeg):
            if deg == 0:
                q.append(course)
        taken = 0
        while len(q) != 0:
            course = q.popleft()
            taken += 1
            for nextCourse in adj[course]:
                indeg[nextCourse] -= 1
                if indeg[nextCourse] == 0:
                    q.append(nextCourse)
        return taken == numCourses