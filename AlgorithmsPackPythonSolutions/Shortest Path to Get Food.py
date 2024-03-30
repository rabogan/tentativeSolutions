class Solution:
    def __init__(self):
        self.dr = [-1, 0, 1, 0]
        self.dc = [0, 1, 0, -1]

    def bfs(self, grid, start):
        rows = len(grid)
        cols = len(grid[0])
        visited = [[False] * cols for _ in range(rows)]
        queue = collections.deque()
        queue.append(start)
        visited[start[0]][start[1]] = True

        level = 0  # Initialize the level

        while queue:
            level += 1  # Increment the level
            size = len(queue)
            for _ in range(size):
                r, c = queue.popleft()

                for d in range(4):
                    nr = self.dr[d] + r
                    nc = self.dc[d] + c
                    if not self.isValid(nr, nc, grid) or visited[nr][nc] or grid[nr][nc] == 'X':
                        continue

                    if grid[nr][nc] == '#':
                        return level

                    if grid[nr][nc] == 'O':
                        visited[nr][nc] = True
                        queue.append((nr, nc))

        return -1

    def isValid(self, r, c, grid):
        if r < 0 or r >= len(grid):
            return False
        if c < 0 or c >= len(grid[0]):
            return False
        return True

    def getFood(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        start = None
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '*':
                    start = (r, c)
                    break

        return self.bfs(grid, start)
