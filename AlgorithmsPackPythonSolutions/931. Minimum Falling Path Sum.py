class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        MAX = 100 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        rows = len(matrix)
        cols = len(matrix[0])

        def fallingSum(r, c):
            if c < 0 or c >= cols:
                return float('inf') / 2

            if r == rows - 1:
                return matrix[r][c]

            if memory[r][c] != -1:
                return memory[r][c]

            dl = fallingSum(r + 1, c - 1)
            down = fallingSum(r + 1, c)
            dr = fallingSum(r + 1, c + 1)

            memory[r][c] = matrix[r][c] + min(dl, down, dr)
            return memory[r][c]

        min_sum = float('inf')
        for c in range(cols):
            min_sum = min(min_sum, fallingSum(0, c))
        return min_sum
