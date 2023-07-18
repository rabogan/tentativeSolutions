class Solution:
    class UnionFind:
        def __init__(self, n):
            self.rank = [1] * n
            self.parent = list(range(n))
            self.forests = n

        def link(self, x, y):
            if self.rank[x] > self.rank[y]:
                x, y = y, x
            self.parent[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1

        def find_set(self, x):
            if x != self.parent[x]:
                self.parent[x] = self.find_set(self.parent[x])
            return self.parent[x]

        def union_sets(self, x, y):
            x, y = self.find_set(x), self.find_set(y)
            if x != y:
                self.link(x, y)
                self.forests -= 1
            return x != y

    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1

        uf = self.UnionFind(n)
        for edge in connections:
            uf.union_sets(edge[0], edge[1])

        return uf.forests - 1
