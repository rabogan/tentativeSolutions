class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]

        def isValid(r: int, c: int, grid: List[List[int]]) -> bool:
            if r < 0 or r >= len(grid):
                return False
            if c < 0 or c >= len(grid[0]):
                return False
            return True

        def onBoundary(r: int, c: int, grid: List[List[int]]) -> bool:
            if r == 0 or r == len(grid) - 1:
                return True
            if c == 0 or c == len(grid[0]) - 1:
                return True
            return False

        def dfs(r: int, c: int, grid: List[List[int]], CCIDS: List[List[bool]], ccid: int) -> None:
            nonlocal touches_boundary
            if not isValid(r, c, grid) or CCIDS[r][c] or grid[r][c] == 1:
                return

            if onBoundary(r, c, grid):
                touches_boundary = True

            CCIDS[r][c] = ccid

            for d in range(4):
                dfs(r + dr[d], c + dc[d], grid, CCIDS, ccid)

        rows = len(grid)
        cols = len(grid[0])
        connectedComponentIDS = [[False] * cols for _ in range(rows)]
        ccid = 0
        count = 0

        for r in range(rows):
            for c in range(cols):
                if not grid[r][c] and not connectedComponentIDS[r][c]:
                    touches_boundary = False
                    dfs(r, c, grid, connectedComponentIDS, ccid + 1)
                    count += not touches_boundary

        return count
