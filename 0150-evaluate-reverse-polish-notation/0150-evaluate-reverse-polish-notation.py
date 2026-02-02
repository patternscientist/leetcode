class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        st = deque()
        funcs = {"+" : lambda n1,n2 : n1+n2,
                "-" : lambda n1,n2 : n1-n2,
                "*" : lambda n1,n2 : n1*n2,
                "/" : lambda n1,n2 : int(floor(float(n1)/n2)) if float(n1)/n2 > 0 else int(ceil(float(n1)/n2))}
        for token in tokens:
            if token in funcs:
                n2 = st.pop()
                n1 = st.pop()
                st.append(funcs[token](n1,n2))
            else:
                st.append(int(token))
        return st[-1]