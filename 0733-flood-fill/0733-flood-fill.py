class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        ogColor = image[sr][sc]
        if ogColor == color: return image
        m = len(image)
        n = len(image[0])
        q = deque()
        image[sr][sc] = color
        q.append((sr,sc))
        dr = [0,-1,0,1]
        dc = [-1,0,1,0]
        while len(q) != 0:
            r,c = q.popleft()
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if (0 <= nr and nr < m and
                    0 <= nc and nc < n and 
                    image[nr][nc] == ogColor):
                    image[nr][nc] = color
                    q.append((nr,nc))
        return image
        