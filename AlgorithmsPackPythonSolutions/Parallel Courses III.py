class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        def addEdge(graph, from_node, to):
            graph[from_node].append(to)

        def topSort(graph, time):
            nodes = len(graph)
            incomingEdges = [0] * nodes

            for i in range(nodes):
                for j in graph[i]:
                    incomingEdges[j] += 1

            q = deque()
            for i in range(nodes):
                if incomingEdges[i] == 0:
                    q.append(i)

            result = [0] * nodes
            while q:
                cur = q.popleft()
                result[cur] += time[cur]

                for j in graph[cur]:
                    incomingEdges[j] -= 1
                    if incomingEdges[j] == 0:
                        q.append(j)
                    result[j] = max(result[j], result[cur])

            return result

        graph = [[] for _ in range(n)]
        for rel in relations:
            addEdge(graph, rel[0] - 1, rel[1] - 1)

        timeComp = topSort(graph, time)
        res = max(timeComp)
        return res
