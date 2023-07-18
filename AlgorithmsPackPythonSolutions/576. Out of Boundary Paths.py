class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MAX = 50 + 1
        memory = [[[-1] * MAX for _ in range(MAX)] for _ in range(MAX)]
        rows = m
        cols = n
        moves = maxMove
        MOD = int(1e9) + 7

        def count(r, c, move):
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return 1

            if move == moves:
                return 0

            if memory[r][c][move] != -1:
                return memory[r][c][move]

            ret = count(r + 1, c, move + 1)
            ret += count(r - 1, c, move + 1)
            ret %= MOD

            ret += count(r, c + 1, move + 1)
            ret %= MOD

            ret += count(r, c - 1, move + 1)
            ret %= MOD

            memory[r][c][move] = ret
            return ret

        return count(startRow, startColumn, 0)
