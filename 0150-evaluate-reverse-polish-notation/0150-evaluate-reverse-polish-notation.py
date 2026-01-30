class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = {"+","-","*","/"}
        s = deque()
        for token in tokens:
            if token in ops:
                n2 = s.pop()
                n1 = s.pop()
                if token == "+":
                    s.append(n1+n2)
                elif token == "-":
                    s.append(n1-n2)
                elif token == "*":
                    s.append(n1*n2)
                else:
                    s.append(floor(n1/n2) if n1/n2 >= 0 else ceil(n1/n2))
            else:
                s.append(int(token))
        return s.pop()