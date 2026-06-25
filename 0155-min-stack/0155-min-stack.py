class MinStack:

    def __init__(self):
        self.st = deque()
        self.mins = deque()

    def push(self, value: int) -> None:
        self.st.append(value)
        if len(self.mins) == 0 or self.mins[-1] >= value:
            self.mins.append(value)

    def pop(self) -> None:
        val = self.st[-1]
        self.st.pop()
        if self.mins[-1] == val:
            self.mins.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.mins[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()