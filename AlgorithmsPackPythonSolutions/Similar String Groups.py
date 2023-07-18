class UnionFind:
    def __init__(self, n):
        self.forests = n
        self.rank = [1] * n
        self.parent = list(range(n))

    def link(self, x, y):
        if self.rank[x] > self.rank[y]:
            x, y = y, x
        self.parent[x] = y
        if self.rank[x] == self.rank[y]:
            self.rank[y] += 1

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


class Solution:
    def isSimilar(self, a: str, b: str) -> bool:
        diff = 0
        for i in range(len(a)):
            if a[i] != b[i]:
                diff += 1
            if diff > 2:
                return False
        return True

    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i + 1, n):
                if self.isSimilar(strs[i], strs[j]):
                    uf.union_set(i, j)
        return uf.forests
