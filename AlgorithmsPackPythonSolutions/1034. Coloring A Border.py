class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]

        def isValid(r: int, c: int, grid: List[List[int]]) -> bool:
            if r < 0 or r >= len(grid):
                return False
            if c < 0 or c >= len(grid[0]):
                return False
            return True

        def dfs(r: int, c: int, grid: List[List[int]], visited: List[List[bool]], color: int) -> None:
            if not isValid(r, c, grid) or visited[r][c] or grid[r][c] != color:
                return

            visited[r][c] = True

            for d in range(4):
                dfs(r + dr[d], c + dc[d], grid, visited, color)

        def colorIn(grid: List[List[int]], visited: List[List[bool]], color: int) -> None:
            rows = len(grid)
            cols = len(grid[0])

            for r in range(rows):
                for c in range(cols):
                    for d in range(4):
                        if not visited[r][c]:
                            continue

                        nr = dr[d] + r
                        nc = dc[d] + c

                        if not isValid(nr, nc, grid) or not visited[nr][nc]:
                            grid[r][c] = color

        rows = len(grid)
        cols = len(grid[0])
        visited = [[False] * cols for _ in range(rows)]
        dfs(row, col, grid, visited, grid[row][col])
        colorIn(grid, visited, color)
        return grid
