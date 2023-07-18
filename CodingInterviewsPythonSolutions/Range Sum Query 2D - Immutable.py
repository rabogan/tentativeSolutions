class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        self.accum = matrix
        self.rowCumSum()
        self.colCumSum()
    
    def rowCumSum(self):
        rows = len(self.accum)
        cols = len(self.accum[0])
        for r in range(rows):
            for c in range(1, cols):
                self.accum[r][c] += self.accum[r][c - 1]
    
    def colCumSum(self):
        rows = len(self.accum)
        cols = len(self.accum[0])
        for c in range(cols):
            for r in range(1, rows):
                self.accum[r][c] += self.accum[r - 1][c]
    
    def cellSum(self, r, c):
        if r < 0 or c < 0:
            return 0
        return self.accum[r][c]
    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (
            self.cellSum(row2, col2)
            - self.cellSum(row2, col1 - 1)
            - self.cellSum(row1 - 1, col2)
            + self.cellSum(row1 - 1, col1 - 1)
        )
