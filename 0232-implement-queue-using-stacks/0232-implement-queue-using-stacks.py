class MyQueue:

    def __init__(self):
        self.front = deque()
        self.back  = deque()

    def pour(self) -> None:
        if len(self.front) != 0:
            return 
        while len(self.back) != 0:
            self.front.append(self.back.pop())

    def push(self, x: int) -> None:
        self.back.append(x)

    def pop(self) -> int:
        self.pour()
        return self.front.pop()

    def peek(self) -> int:
        self.pour()
        return self.front[-1]

    def empty(self) -> bool:
        return len(self.front) == len(self.back) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()