class Solution:
    def backtrack(self, graph, start, end, ans, cur):
        if start == end:
            ans.append(cur.copy())
            return

        for i in range(len(graph[start])):
            cur.append(graph[start][i])
            self.backtrack(graph, graph[start][i], end, ans, cur)
            cur.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        cur = [0]
        self.backtrack(graph, 0, len(graph) - 1, ans, cur)
        return ans
