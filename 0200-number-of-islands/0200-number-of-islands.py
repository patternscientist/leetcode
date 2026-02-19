class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dr = [0,-1,0,1]
        dc = [-1,0,1,0]
        q = deque()
        islands = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] != "1":
                    continue 
                islands += 1
                grid[r][c] = "X"
                q.append((r,c))
                while len(q) != 0:
                    currR,currC = q.popleft()
                    for k in range(4):
                        nr = currR + dr[k]
                        nc = currC + dc[k]
                        if (0 <= nr and nr < m and 
                            0 <= nc and nc < n and
                            grid[nr][nc] == "1"):
                            grid[nr][nc] = "X"
                            q.append((nr,nc))
        return islands