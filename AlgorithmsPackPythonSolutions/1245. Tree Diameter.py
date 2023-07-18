class Solution:
    def addEdge(self, graph, from_node, to):
        graph[from_node].append(to)
        graph[to].append(from_node)

    def dfs(self, graph, node, parent=-1):
        mxH1 = 0
        mxH2 = 0
        for cur in graph[node]:
            if cur == parent:
                continue
            h = self.dfs(graph, cur, node)
            if h > mxH1:
                mxH2 = mxH1
                mxH1 = h
            elif h > mxH2:
                mxH2 = h
        self.mxDia = max(self.mxDia, mxH1 + mxH2)
        return 1 + mxH1

    def treeDiameter(self, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(len(edges) + 1)]
        for e in edges:
            self.addEdge(graph, e[0], e[1])
        self.mxDia = 0
        self.dfs(graph, 0)
        return self.mxDia
