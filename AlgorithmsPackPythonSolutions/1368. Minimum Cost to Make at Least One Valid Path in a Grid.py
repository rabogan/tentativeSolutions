class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        dr = [0, 0, 1, -1]
        dc = [1, -1, 0, 0]

        def isValid(r, c, grid):
            if r < 0 or r >= len(grid):
                return False
            if c < 0 or c >= len(grid[0]):
                return False
            return True

        rows = len(grid)
        cols = len(grid[0])

        OO = int(1e9)
        dist = [[OO] * cols for _ in range(rows)]
        dist[0][0] = 0

        deq = deque()
        deq.append([0, 0])

        while deq:
            r, c = deq.popleft()
            for d in range(4):
                nr = dr[d] + r
                nc = dc[d] + c
                edgeWeight = 1 if d != (grid[r][c] - 1) else 0
                nDist = dist[r][c] + edgeWeight

                if not isValid(nr, nc, grid) or nDist >= dist[nr][nc]:
                    continue

                dist[nr][nc] = nDist

                if edgeWeight == 0:
                    deq.appendleft([nr, nc])
                else:
                    deq.append([nr, nc])

        return dist[rows - 1][cols - 1]
