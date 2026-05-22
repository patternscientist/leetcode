class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        m,n  = len(s),len(t)
        if n > m:
            return ""
        need = [0] * 58
        for ch in t:
            need[ord(ch)-ord('A')] += 1
        missing   = n
        l         = 0
        INF       = int(1e5)+1
        bestLen   = INF
        bestStart = 0
        for r in range(m):
            sr = s[r]
            if need[ord(sr)-ord('A')] > 0:
                missing -= 1
            need[ord(sr)-ord('A')] -= 1
            while missing == 0:
                winLen = r-l+1
                if winLen < bestLen:
                    bestLen   = winLen
                    bestStart = l
                sl = s[l]
                need[ord(sl)-ord('A')] += 1
                if need[ord(sl)-ord('A')] > 0:
                    missing += 1
                l += 1
        return "" if bestLen == INF else s[bestStart:bestStart+bestLen]