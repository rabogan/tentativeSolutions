class Solution:
    RED = 0
    BLUE = 1
    OO = int(1e9)

    def addEdge(self, graph: List[List[List[int]]], from_node: int, to_node: int, color: int) -> None:
        graph[from_node].append([to_node, color])

    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        
        for r in redEdges:
            self.addEdge(graph, r[0], r[1], self.RED)
        for b in blueEdges:
            self.addEdge(graph, b[0], b[1], self.BLUE)
        
        return self.bfs(graph, 0)

    def bfs(self, graph: List[List[List[int]]], node: int) -> List[int]:
        q = deque()
        q.append([node, self.RED])
        q.append([node, self.BLUE])

        nodes = len(graph)
        visited = [[self.OO, self.OO] for _ in range(nodes)]
        visited[node][self.RED] = visited[node][self.BLUE] = 0

        result = [-1] * nodes
        result[node] = 0

        level = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                to, color = q.popleft()

                for e in graph[to]:
                    if e[1] != color and visited[e[0]][e[1]] == self.OO:
                        q.append([e[0], e[1]])
                        visited[e[0]][e[1]] = level + 1

                        if result[e[0]] == -1:
                            result[e[0]] = level + 1
            level += 1

        return result
