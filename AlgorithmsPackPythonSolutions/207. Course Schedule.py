class Solution:
    def add_edge(self, graph, from_node, to):
        graph[from_node].append(to)

    def topSort(self, graph, visited):
        nodes = len(graph)
        indegree = [0] * nodes
        for i in range(nodes):
            for j in graph[i]:
                indegree[j] += 1

        ready = deque()
        for i in range(nodes):
            if indegree[i] == 0:
                ready.append(i)

        result = []
        while ready:
            cur = ready.popleft()
            result.append(cur)
            if visited[cur]:
                return False
            visited[cur] = True
            for node in graph[cur]:
                if visited[node]:
                    return False
                indegree[node] -= 1
                if indegree[node] == 0:
                    ready.append(node)

        if len(result) == nodes:
            return True
        else:
            return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if numCourses == 0:
            return True

        graph = [[] for _ in range(numCourses)]

        for p in prerequisites:
            self.add_edge(graph, p[1], p[0])

        visited = [False] * numCourses

        return self.topSort(graph, visited)
