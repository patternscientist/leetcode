class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        fresh = 0
        q = deque()
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 2:
                    q.append((r,c))
                elif grid[r][c] == 1:
                    fresh += 1
        minutes = 0
        dr = [0,-1,0,1]
        dc = [-1,0,1,0]
        while len(q) != 0:
            sz = len(q)
            madeRotten = False
            for _ in range(sz):
                r,c = q.popleft()
                for k in range(4):
                    nr = r + dr[k]
                    nc = c + dc[k]
                    if (0 <= nr and nr < m and
                        0 <= nc and nc < n and 
                        grid[nr][nc] == 1):
                        grid[nr][nc] = 2
                        fresh -= 1
                        madeRotten = True
                        q.append((nr,nc))
            if madeRotten:
                minutes += 1
        return minutes if fresh == 0 else -1