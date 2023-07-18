class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        class UnionFind:
            def __init__(self, n):
                self.forests = n
                self.rank = [1] * n
                self.parent = list(range(n))

            def find_set(self, x):
                if x == self.parent[x]:
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

        class Edge:
            def __init__(self, from_, to, weight, index):
                self.from_ = from_
                self.to = to
                self.weight = weight
                self.index = index

            def __lt__(self, other):
                return self.weight < other.weight

        def MST_Kruskal(edgeList, nodes, edgesAdd, edgesIgnore):
            uf = UnionFind(nodes)
            mstCost = 0

            for e in edgesAdd:
                if uf.union_set(e.from_, e.to):
                    mstCost += e.weight

            for e in edgeList:
                if e.index not in edgesIgnore and uf.union_set(e.from_, e.to):
                    mstCost += e.weight

            return mstCost

        pseudoCritical = []
        critical = []
        edgeList = [Edge(e[0], e[1], e[2], i) for i, e in enumerate(edges)]
        edgeList.sort()

        mstCost1 = MST_Kruskal(edgeList, n, [], [])

        for e in edgeList:
            mstCost2 = MST_Kruskal(edgeList, n, [e], [])
            if mstCost2 > mstCost1:
                continue

            mstCost3 = MST_Kruskal(edgeList, n, [], [e.index])
            if mstCost3 == mstCost1:
                pseudoCritical.append(e.index)
            else:
                critical.append(e.index)

        return [critical, pseudoCritical]
