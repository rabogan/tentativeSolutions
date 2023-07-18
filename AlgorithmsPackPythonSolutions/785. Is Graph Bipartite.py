class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colorConflict = False
        
        def dfs(graph, node, colors, assignCol=1):
            if colors[node] == 0:
                colors[node] = assignCol
            else:
                if colors[node] != assignCol:
                    nonlocal colorConflict
                    colorConflict = True
                return
            
            for cur in graph[node]:
                dfs(graph, cur, colors, 3 - assignCol)
        
        n = len(graph)
        colors = [0] * n
        
        for i in range(n):
            if colors[i] == 0:
                dfs(graph, i, colors)
                if colorConflict:
                    return False
        
        return True
