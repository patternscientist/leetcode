class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj   = [[] for _ in range(numCourses)]
        indeg = [0]*numCourses
        for preq in prerequisites:
            a_i,b_i = preq
            adj[b_i].append(a_i)
            indeg[a_i] += 1
        q = deque()
        for course in range(numCourses):
            if indeg[course] == 0:
                q.append(course)
        taken = 0
        while len(q) != 0:
            cur = q.popleft()
            taken += 1
            for other in adj[cur]:
                indeg[other] -= 1
                if indeg[other] == 0:
                    q.append(other)
        return taken == numCourses