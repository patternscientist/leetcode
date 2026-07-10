class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m,n = len(s),len(t)
        if m < n:
            return ""
        need = [0] * 256
        for ch in t:
            need[ord(ch)] += 1

        missing = n
        l = 0
        INF = int(1e5)+1 # bigger than any possible len
        bestLen = INF
        bestStart = 0
        for r in range(m):
            cr = s[r]

            if need[ord(cr)] > 0:
                missing -= 1
            
            need[ord(cr)] -= 1

            while missing == 0:
                winLen = r-l+1
                if winLen < bestLen:
                    bestLen = winLen
                    bestStart = l
                cl = s[l]
                need[ord(cl)] += 1
                if need[ord(cl)] > 0:
                    missing += 1
                l += 1

        return "" if bestLen == INF else s[bestStart:bestStart+bestLen]