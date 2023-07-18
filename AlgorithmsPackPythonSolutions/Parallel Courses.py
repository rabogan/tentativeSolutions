class Solution:
    def addEdge(self, graph, from_node, to):
        graph[from_node].append(to)

    def topSort(self, graph):
        nodes = len(graph)
        incomingEdges = [0] * nodes
        for i in range(nodes):
            for j in graph[i]:
                incomingEdges[j] += 1

        q = deque()
        for i in range(nodes):
            if incomingEdges[i] == 0:
                q.append(i)

        nodesFound = 0
        result = 0
        while q:
            sz = len(q)
            while sz:
                cur = q.popleft()
                nodesFound += 1
                for j in graph[cur]:
                    incomingEdges[j] -= 1
                    if incomingEdges[j] == 0:
                        q.append(j)
                sz -= 1
            result += 1

        if nodesFound != nodes:
            return -1
        return result

    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for rel in relations:
            self.addEdge(graph, rel[0] - 1, rel[1] - 1)

        return self.topSort(graph)
