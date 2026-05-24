class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m,n = len(matrix),len(matrix[0])
        rMin,rMax = 0,m-1
        cMin,cMax = 0,n-1
        ans = []
        while rMin <= rMax and cMin <= cMax:
            for c in range(cMin,cMax+1):
                ans.append(matrix[rMin][c])
            rMin += 1
            if rMin > rMax:
                break
            for r in range(rMin,rMax+1):
                ans.append(matrix[r][cMax])
            cMax -= 1
            if cMin > cMax:
                break
            for c in range(cMax,cMin-1,-1):
                ans.append(matrix[rMax][c])
            rMax -= 1
            if rMin > rMax:
                break
            for r in range(rMax,rMin-1,-1):
                ans.append(matrix[r][cMin])
            cMin += 1
        return ans