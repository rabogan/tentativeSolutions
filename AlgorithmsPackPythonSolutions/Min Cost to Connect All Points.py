class UnionFind:
    def __init__(self, n):
        self.forests = n
        self.rank = [1] * n
        self.parent = list(range(n))

    def find_set(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find_set(self.parent[x])
        return self.parent[x]

    def union_set(self, x, y):
        x = self.find_set(x)
        y = self.find_set(y)
        if x != y:
            self.link(x, y)
            self.forests -= 1
        return x != y

    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            x, y = y, x
        self.parent[x] = y
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edgeList = []
        for i in range(n):
            for j in range(i, n):
                cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edgeList.append((i, j, cost))

        edgeList.sort(key=lambda e: e[2])
        uf = UnionFind(n)
        mstCost = 0

        for e in edgeList:
            if uf.union_set(e[0], e[1]):
                mstCost += e[2]

        return mstCost
