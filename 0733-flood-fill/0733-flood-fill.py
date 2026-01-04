class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        from queue import Queue

        og = image[sr][sc]
        if og == color: return image

        m = len(image)
        n = len(image[0])

        q = Queue(maxsize=m * n)
        q.put((sr,sc))
        image[sr][sc] = color

        while not q.empty():
            (r,c) = q.get()
            dr = [-1,0,1,0]
            dc = [0,1,0,-1]
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if (nr >= 0 and nr < m and 
                    nc >= 0 and nc < n and 
                    image[nr][nc] == og):
                    q.put((nr,nc))
                    image[nr][nc] = color

        return image

        
