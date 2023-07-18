class Solution:
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]
    
    class Cell:
        def __init__(self, r, c):
            self.r = r
            self.c = c
    
    def isValid(self, r, c, heights):
        if r < 0 or r >= len(heights):
            return False
        if c < 0 or c >= len(heights[0]):
            return False
        return True
    
    def bfs(self, heights, visited, starts):
        q = deque()
        for ce in starts:
            q.append(ce)
            visited[ce.r][ce.c] = True
        
        while q:
            cur = q.popleft()
            r, c = cur.r, cur.c
            
            for d in range(4):
                nr = r + self.dr[d]
                nc = c + self.dc[d]
                if not self.isValid(nr, nc, heights) or visited[nr][nc] or heights[nr][nc] < heights[r][c]:
                    continue
                
                visited[nr][nc] = True
                q.append(self.Cell(nr, nc))
    
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        
        rows, cols = len(heights), len(heights[0])
        atlanticGraph = [[False] * cols for _ in range(rows)]
        pacificGraph = [[False] * cols for _ in range(rows)]
        atlanticStarts = []
        pacificStarts = []
        
        for r in range(rows):
            atlanticStarts.append(self.Cell(r, cols - 1))
            pacificStarts.append(self.Cell(r, 0))
        
        for c in range(cols):
            atlanticStarts.append(self.Cell(rows - 1, c))
            pacificStarts.append(self.Cell(0, c))
        
        self.bfs(heights, atlanticGraph, atlanticStarts)
        self.bfs(heights, pacificGraph, pacificStarts)
        
        result = []
        for r in range(rows):
            for c in range(cols):
                if atlanticGraph[r][c] and pacificGraph[r][c]:
                    result.append([r, c])
        
        return result
