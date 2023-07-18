class Solution:
    def add_edge(self, graph, from_node, to):
        graph[from_node].append(to)

    def topSort(self, graph):
        indegrees = defaultdict(int)

        for node in graph.values():
            for j in node:
                indegrees[j] += 1

        q = deque()
        for node in graph:
            if node not in indegrees:
                q.append(node)

        ordering = []

        while q:
            if len(q) > 1:
                return []
            cur = q.popleft()
            ordering.append(cur)

            for j in graph[cur]:
                indegrees[j] -= 1
                if indegrees[j] == 0:
                    q.append(j)

        if len(ordering) != len(graph):
            return []
        return ordering

    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        graph = defaultdict(list)

        for seq in sequences:
            for i in range(len(seq) - 1):
                self.add_edge(graph, seq[i], seq[i + 1])

        for seq in sequences:
            if len(seq) == 1 and seq[0] not in graph:
                graph[seq[0]] = []

        ordering = self.topSort(graph)
        return ordering == nums
