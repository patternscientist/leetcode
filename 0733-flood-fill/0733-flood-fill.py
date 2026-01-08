class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        og = image[sr][sc]
        if og == color: return image

        m = len(image)
        n = len(image[0])

        q = deque(maxlen=m*n)
        image[sr][sc] = color
        q.append((sr,sc))
        while len(q) != 0:
            (r,c) = q.popleft()
            dr = (-1,0,1,0)
            dc = (0,1,0,-1)
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if (nr >= 0 and nr < m and 
                    nc >= 0 and nc < n and
                   image[nr][nc] == og):
                   q.append((nr,nc))
                   image[nr][nc] = color
        return image
        