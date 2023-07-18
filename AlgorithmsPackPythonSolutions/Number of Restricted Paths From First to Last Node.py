import heapq
from typing import List

class Solution:
    MOD = int(1e9 + 7)
    OO = int(2e9 + 10)
    MAX_N = int(2e4 + 1)

    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        memory = [-1] * self.MAX_N

        class Edge:
            def __init__(self, to, weight):
                self.to = to
                self.weight = weight

        def dijkstra(adjList, source):
            dist = [self.OO] * n
            vis = [False] * n
            dist[source] = 0

            q = []
            heapq.heappush(q, (0, source))

            while q:
                minWeight, minIndex = heapq.heappop(q)

                if vis[minIndex]:
                    continue

                for edge in adjList[minIndex]:
                    to = edge.to
                    weight = edge.weight

                    if dist[to] > dist[minIndex] + weight:
                        dist[to] = dist[minIndex] + weight
                        heapq.heappush(q, (dist[to], to))

                vis[minIndex] = True

            return dist

        def countPaths(source, target, adjList, dist):
            if source == target:
                return 1

            if memory[source] != -1:
                return memory[source]

            ret = 0
            for edge in adjList[source]:
                if dist[source] > dist[edge.to]:
                    ret += countPaths(edge.to, target, adjList, dist)
                    ret %= self.MOD

            memory[source] = ret
            return ret

        adjList = [[] for _ in range(n)]
        for road in edges:
            from_, to, cost = road[0] - 1, road[1] - 1, road[2]
            adjList[from_].append(Edge(to, cost))
            adjList[to].append(Edge(from_, cost))

        dist = dijkstra(adjList, n - 1)
        memory = [-1] * self.MAX_N

        return countPaths(0, n - 1, adjList, dist)
