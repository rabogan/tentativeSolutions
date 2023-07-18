class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [[0] * 9 for _ in range(9)]
        cols = [[0] * 9 for _ in range(9)]
        box = [[[0] * 9 for _ in range(3)] for _ in range(3)]
        emptyRow = []
        emptyCol = []

        def set_cell(d, r, c, value):
            rows[r][d] = cols[c][d] = box[r // 3][c // 3][d] = value

        def can_place(d, r, c):
            return not rows[r][d] and not cols[c][d] and not box[r // 3][c // 3][d]

        def backtrack(idx):
            if idx >= len(emptyRow):
                return True

            r = emptyRow[idx]
            c = emptyCol[idx]

            for d in range(9):
                if can_place(d, r, c):
                    set_cell(d, r, c, 1)
                    board[r][c] = str(d + 1)

                    if backtrack(idx + 1):
                        return True

                    set_cell(d, r, c, 0)
                    board[r][c] = '.'

            return False

        # Mark initial reserved values
        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    d = int(board[r][c]) - 1
                    set_cell(d, r, c, 1)
                else:
                    emptyRow.append(r)
                    emptyCol.append(c)

        backtrack(0)
