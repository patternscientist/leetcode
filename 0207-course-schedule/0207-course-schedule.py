class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        adj = [[] for _ in range(numCourses)]
        indeg = [0]*numCourses
        
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
            c = q.popleft()
            taken += 1
            for d in adj[c]:
                indeg[d] -= 1
                if indeg[d] == 0:
                    q.append(d)
        
        return taken == numCourses
        
