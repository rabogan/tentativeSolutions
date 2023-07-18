class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])

        startRow = 0
        startCol = cols - 1

        while startRow < rows and startCol >= 0:
            if matrix[startRow][startCol] == target:
                return True
            elif matrix[startRow][startCol] < target:
                startRow += 1
            else:
                startCol -= 1

        return False
