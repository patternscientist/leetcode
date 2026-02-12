class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m,n = len(mat),len(mat[0])
        dist = [[-1 for _ in range(n)] for _ in range(m)]
        q = deque()
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 0:
                    dist[r][c] = 0
                    q.append((r,c))
        dr = [0,-1,0,1]
        dc = [-1,0,1,0]
        while len(q) != 0:
            r,c = q.popleft()
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if (0 <= nr and 
                    nr < m  and 
                    0 <= nc and 
                    nc < n  and 
                    dist[nr][nc] == -1):
                    dist[nr][nc] = dist[r][c]+1
                    q.append((nr,nc))
        return dist
