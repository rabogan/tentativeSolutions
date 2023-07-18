class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        class Edge:
            def __init__(self, to: int, built: bool):
                self.to = to
                self.built = built

        def add_undirected_edge(graph, from_, to):
            graph[from_].append(Edge(to, True))
            graph[to].append(Edge(from_, False))

        def dfs(graph, node, visited, reorient_count):
            visited[node] = True

            for e in graph[node]:
                if not visited[e.to]:
                    reorient_count[0] += e.built
                    dfs(graph, e.to, visited, reorient_count)

        reorient_count = [0]
        graph = [[] for _ in range(n)]
        visited = [False] * n

        for edge in connections:
            add_undirected_edge(graph, edge[0], edge[1])

        dfs(graph, 0, visited, reorient_count)

        return reorient_count[0]
