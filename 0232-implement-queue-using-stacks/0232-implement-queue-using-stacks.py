class MyQueue:

    def __init__(self):
        self.in_  = deque()
        self.out = deque()

    def pour(self) -> None:
        if len(self.out) != 0: return
        while len(self.in_) != 0:
            self.out.append(self.in_.pop())

    def push(self, x: int) -> None:
        self.in_.append(x)

    def pop(self) -> int:
        self.pour()
        return self.out.pop()

    def peek(self) -> int:
        self.pour()
        return self.out[-1]

    def empty(self) -> bool:
        return len(self.in_) == 0 and len(self.out) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()