class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mp = {')':'(', '}':'{',']':'['}
        st = deque()
        for c in s:
            if c == '(' or c == '{' or c == '[':
                st.append(c)
            elif len(st) == 0 or st.pop() != mp[c]:
                return False
        return len(st) == 0