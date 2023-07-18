class Solution:
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    def isValid(self, r, c, matrix):
        if r < 0 or r >= len(matrix):
            return False
        if c < 0 or c >= len(matrix[0]):
            return False
        return True

    def biggerNeighboursAndEdges(self, r, c, matrix):
        edges = []
        incomingEdges = 0

        for d in range(4):
            nr = self.dr[d] + r
            nc = self.dc[d] + c
            if not self.isValid(nr, nc, matrix):
                continue

            if matrix[r][c] < matrix[nr][nc]:
                edges.append((nr, nc))
            elif matrix[r][c] > matrix[nr][nc]:
                incomingEdges += 1

        return edges, incomingEdges

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        incomingEdges = [[0] * cols for _ in range(rows)]
        q = []
        for r in range(rows):
            for c in range(cols):
                incomingEdges[r][c] = self.biggerNeighboursAndEdges(r, c, matrix)[1]
                if incomingEdges[r][c] == 0:
                    q.append((r, c))

        levels = 0
        while q:
            level_sz = len(q)
            while level_sz > 0:
                r, c = q.pop(0)
                level_sz -= 1
                biggerNeighbours = self.biggerNeighboursAndEdges(r, c, matrix)[0]

                for node in biggerNeighbours:
                    incomingEdges[node[0]][node[1]] -= 1
                    if incomingEdges[node[0]][node[1]] == 0:
                        q.append(node)

            levels += 1

        return levels
