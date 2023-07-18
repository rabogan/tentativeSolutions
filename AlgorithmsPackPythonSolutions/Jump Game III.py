class Solution:
    def process(self, q, visited, arr, index):
        if index < 0 or index >= len(arr) or visited[index]:
            return False
        if arr[index] == 0:
            return True
        q.append(index)
        visited[index] = True
        return False
    
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        if arr[start] == 0:
            return True
        
        q = collections.deque()
        q.append(start)
        visited = [False] * n
        visited[start] = True
        
        while q:
            cur = q.popleft()
            
            if self.process(q, visited, arr, cur + arr[cur]) or self.process(q, visited, arr, cur - arr[cur]):
                return True
        
        return False
