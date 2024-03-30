class Solution:
    def process(self, q, visited, num, goal):
        if num == goal:
            return True
        
        if 0 <= num <= 1000 and not visited[num]:
            q.append(num)
            visited[num] = True
        
        return False
    
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        q = collections.deque()
        visited = [False] * 1001
        q.append(start)
        visited[start] = True
        
        level = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                x = q.popleft()
                for num in nums:
                    if (self.process(q, visited, x + num, goal) or
                        self.process(q, visited, x - num, goal) or
                        self.process(q, visited, x ^ num, goal)):
                        return level + 1
            level += 1
        
        return -1
