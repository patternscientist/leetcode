class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m,n = len(grid),len(grid[0])
        q = deque()
        dr = [-1,0,1,0]
        dc = [0,1,0,-1]
        islands = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] != '1':
                    continue
                grid[r][c] = 'X'
                q.append((r,c))
                while len(q) != 0:
                    (R,C) = q.popleft()
                    for k in range(4):
                        nr = R + dr[k]
                        nc = C + dc[k]
                        if (0 <= nr and nr < m and 
                            0 <= nc and nc < n and 
                            grid[nr][nc] == '1'):
                            grid[nr][nc] = 'X'
                            q.append((nr,nc))
                islands += 1
        return islands