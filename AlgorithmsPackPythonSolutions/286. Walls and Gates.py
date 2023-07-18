class Solution:
    def isValid(self, r, c, rooms):
        if r < 0 or r >= len(rooms):
            return False
        if c < 0 or c >= len(rooms[0]):
            return False
        return True

    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms:
            return
        
        INF = 2147483647
        rows, cols = len(rooms), len(rooms[0])
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        
        def fillSpaces(starts):
            q = deque()
            visited = [[False] * cols for _ in range(rows)]
            for cell in starts:
                q.append(cell)
                visited[cell[0]][cell[1]] = True
            
            while q:
                r, c = q.popleft()
                
                for d in range(4):
                    nr = dr[d] + r
                    nc = dc[d] + c
                    if not self.isValid(nr, nc, rooms) or visited[nr][nc] or rooms[nr][nc] == -1:
                        continue
                    
                    if rooms[nr][nc] == INF:
                        rooms[nr][nc] = rooms[r][c] + 1
                        q.append((nr, nc))
                        visited[nr][nc] = True
        
        starts = []
        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    starts.append((r, c))
        
        fillSpaces(starts)
