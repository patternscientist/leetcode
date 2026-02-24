class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m,n = len(grid),len(grid[0])
        q = deque()
        dr = [0,-1,0,1]
        dc = [-1,0,1,0]
        islands = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] != '1':
                    continue
                grid[r][c] = 'X'
                q.append((r,c))
                islands += 1
                while len(q) != 0:
                    i,j = q.popleft()
                    for k in range(4):
                        ni = i + dr[k]
                        nj = j + dc[k]
                        if (0 <= ni and ni < m and
                            0 <= nj and nj < n and 
                            grid[ni][nj] == '1'):
                            grid[ni][nj] = 'X'
                            q.append((ni,nj))
        return islands