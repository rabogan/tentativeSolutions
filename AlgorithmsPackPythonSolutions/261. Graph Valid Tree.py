class Solution:
    def bfsCycle(self, graph, node, visited, parent):
        visited[node] = 0
        queue = collections.deque()
        queue.append(node)

        while queue:
            cur = queue.popleft()

            for neighbour in graph[cur]:
                if parent[cur] == neighbour:
                    continue

                if visited[neighbour] == float('inf'):
                    parent[neighbour] = cur
                    visited[neighbour] = visited[cur] + 1
                    queue.append(neighbour)
                else:
                    return True

        return False

    def hasCycle(self, graph):
        nodes = len(graph)
        visited = [float('inf')] * nodes
        parent = [-1] * nodes

        for idx in range(nodes):
            if visited[idx] == float('inf') and self.bfsCycle(graph, idx, visited, parent):
                return True

        return False

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n - 1 != len(edges):
            return False

        graph = [[] for _ in range(n)]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        return not self.hasCycle(graph)
