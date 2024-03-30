class Solution:
    def dijkstra(self, adjList: List[List[Tuple[int, int]]], nodes: int, source: int, target: int) -> int:
        MOD = int(1e9 + 7)
        OO = (int(1e9) + 10) * 200
        
        dist = [OO] * nodes
        dist[source] = 0

        pathCount = [0] * nodes
        pathCount[source] = 1

        pq = [(0, source)]

        while pq:
            minWeight, minIndex = heapq.heappop(pq)
            if minWeight > dist[minIndex]:
                continue
            
            for to, weight in adjList[minIndex]:
                if dist[to] > dist[minIndex] + weight:
                    dist[to] = dist[minIndex] + weight
                    pathCount[to] = pathCount[minIndex]
                    heapq.heappush(pq, (dist[to], to))
                elif dist[to] == dist[minIndex] + weight:
                    pathCount[to] += pathCount[minIndex]
                    pathCount[to] %= MOD
        
        return pathCount[target]

    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adjList = [[] for _ in range(n)]
        for from_, to, cost in roads:
            adjList[from_].append((to, cost))
            adjList[to].append((from_, cost))
        
        return self.dijkstra(adjList, n, 0, n - 1)
