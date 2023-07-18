class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]  # Initialize an empty graph

        def addEdge(graph: List[List[int]], fromNode: int, toNode: int) -> None:
            graph[fromNode].append(toNode)
            graph[toNode].append(fromNode)

        def dfs(graph: List[List[int]], node: int, visited: List[bool]) -> None:
            visited[node] = True

            for cur in graph[node]:
                if not visited[cur]:
                    dfs(graph, cur, visited)

        def countThem(graph: List[List[int]]) -> int:
            visited = [False] * len(graph)
            count = 0

            for i in range(len(graph)):
                if not visited[i]:
                    dfs(graph, i, visited)
                    count += 1

            return count

        for edge in edges:
            addEdge(graph, edge[0], edge[1])

        return countThem(graph)
