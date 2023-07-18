class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        MAX = 100 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        grid = obstacleGrid
        
        def countWays(r, c):
            rows = len(grid)
            cols = len(grid[0])

            if r >= rows or c >= cols or grid[r][c] == 1:
                return 0

            if rows - 1 == r and cols - 1 == c:
                return 1

            if memory[r][c] != -1:
                return memory[r][c]

            down = countWays(r + 1, c)
            right = countWays(r, c + 1)

            memory[r][c] = down + right
            return memory[r][c]

        return countWays(0, 0)
