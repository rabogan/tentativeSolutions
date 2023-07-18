class Solution:
    def backtrack(self, r, n, normDiag, antiDiag, columns, solution, cur):
        if r == n:
            solution.append(cur.copy())
            return

        for c in range(n):
            x = r + c
            y = n - 1 + r - c

            if columns[c] or normDiag[y] or antiDiag[x]:
                continue

            cur[r] = cur[r][:c] + 'Q' + cur[r][c + 1:]
            columns[c] = normDiag[y] = antiDiag[x] = True

            self.backtrack(r + 1, n, normDiag, antiDiag, columns, solution, cur)

            columns[c] = normDiag[y] = antiDiag[x] = False
            cur[r] = cur[r][:c] + '.' + cur[r][c + 1:]

    def solveNQueens(self, n: int) -> List[List[str]]:
        normDiag = [False] * (2 * n - 1)
        antiDiag = [False] * (2 * n - 1)
        columns = [False] * n
        solution = []
        cur = ['.' * n for _ in range(n)]
        self.backtrack(0, n, normDiag, antiDiag, columns, solution, cur)
        return solution
