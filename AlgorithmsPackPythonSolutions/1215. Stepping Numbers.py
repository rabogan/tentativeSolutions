class Solution:
    def inRange(self, low: int, high: int, num: int) -> bool:
        return low <= num <= high

    def process(self, queue: deque, visited: List[int], low: int, high: int, num: int) -> bool:
        if num > high:
            return False

        if self.inRange(low, high, num):
            visited.append(num)

        queue.append(num)
        return True

    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        queue = deque()
        visited = []

        if self.inRange(low, high, 0):
            visited.append(0)

        for i in range(1, 10):
            if self.inRange(low, high, i):
                visited.append(i)
            queue.append(i)

        while queue:
            cur = queue.popleft()
            digit = cur % 10

            if digit != 0 and not self.process(queue, visited, low, high, cur * 10 + digit - 1):
                break
            if digit != 9 and not self.process(queue, visited, low, high, cur * 10 + digit + 1):
                break

        return visited
