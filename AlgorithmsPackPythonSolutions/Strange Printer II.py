class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        rows = len(targetGrid)
        cols = len(targetGrid[0])
        maxColor = 61
        
        rmax = [-1] * maxColor
        rmin = [rows] * maxColor
        cmax = [-1] * maxColor
        cmin = [cols] * maxColor
        
        for r in range(rows):
            for c in range(cols):
                color = targetGrid[r][c]
                rmax[color] = max(rmax[color], r)
                rmin[color] = min(rmin[color], r)
                cmax[color] = max(cmax[color], c)
                cmin[color] = min(cmin[color], c)
        
        graph = [[] for _ in range(maxColor)]
        
        for color in range(maxColor):
            for r in range(rmin[color], rmax[color] + 1):
                for c in range(cmin[color], cmax[color] + 1):
                    if targetGrid[r][c] != color:
                        graph[color].append(targetGrid[r][c])
        
        return len(self.topSort(graph)) > 0
    
    def topSort(self, graph: List[List[int]]) -> List[int]:
        sz = len(graph)
        incomingEdges = [0] * sz
        for i in range(sz):
            for j in graph[i]:
                incomingEdges[j] += 1
        
        queue = deque()
        ordering = []
        
        for i in range(sz):
            if incomingEdges[i] == 0:
                queue.append(i)
        
        while queue:
            i = queue.popleft()
            ordering.append(i)
            
            for j in graph[i]:
                incomingEdges[j] -= 1
                if incomingEdges[j] == 0:
                    queue.append(j)
        
        if len(ordering) != sz:
            ordering.clear()
        
        return ordering
