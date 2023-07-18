class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        is_cycle = False

        def isValid(r: int, c: int, grid: List[List[str]]) -> bool:
            rows = len(grid)
            cols = len(grid[0])
            return r >= 0 and r < rows and c >= 0 and c < cols

        def dfs(r: int, c: int, grid: List[List[str]], visited: List[List[bool]], oldColor: str, parent_row: int = -1, parent_col: int = -1) -> None:
            nonlocal is_cycle

            if not isValid(r, c, grid) or grid[r][c] != oldColor or is_cycle:
                return

            if visited[r][c]:
                is_cycle = True
                return

            visited[r][c] = True

            for d in range(4):
                nr = dr[d] + r
                nc = dc[d] + c

                if nr == parent_row and nc == parent_col:
                    continue

                dfs(nr, nc, grid, visited, oldColor, r, c)

        rows = len(grid)
        cols = len(grid[0])
        visited = [[False] * cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols):
                if not visited[r][c]:
                    is_cycle = False
                    dfs(r, c, grid, visited, grid[r][c])
                    if is_cycle:
                        return True

        return False
