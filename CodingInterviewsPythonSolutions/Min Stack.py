class MinStack:

    def __init__(self):
        self.data = []
        self.mnStack = []

    def push(self, val: int) -> None:
        self.data.append(val)
        if not self.mnStack or val <= self.mnStack[-1]:
            self.mnStack.append(val)

    def pop(self) -> None:
        if self.mnStack[-1] == self.data[-1]:
            self.mnStack.pop()
        self.data.pop()

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.mnStack[-1]
