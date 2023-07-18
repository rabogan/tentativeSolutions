class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        nodes = len(colors)
        graph = [[] for _ in range(nodes)]
        incomingEdges = [0] * nodes
        
        for edge in edges:
            from_node, to_node = edge
            graph[from_node].append(to_node)
            incomingEdges[to_node] += 1
        
        queue = deque()
        colorValues = [[0] * 26 for _ in range(nodes)]
        nodesFound = 0
        result = 0
        
        for i in range(nodes):
            if incomingEdges[i] == 0:
                queue.append(i)
        
        while queue:
            cur = queue.popleft()
            color = ord(colors[cur]) - ord('a')
            colorValues[cur][color] += 1
            nodesFound += 1
            result = max(result, colorValues[cur][color])
            
            for neighbor in graph[cur]:
                incomingEdges[neighbor] -= 1
                if incomingEdges[neighbor] == 0:
                    queue.append(neighbor)
                
                for col in range(26):
                    colorValues[neighbor][col] = max(colorValues[neighbor][col], colorValues[cur][col])
        
        if nodesFound != nodes:
            return -1
        
        return result
