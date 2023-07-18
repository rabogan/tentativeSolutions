class Solution:
    def prefixSumCol(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        for c in range(cols):
            for r in range(1, rows):
                matrix[r][c] += (matrix[r][c] != 0) * matrix[r - 1][c]

    def next_smaller_index(self, heights):
        n = len(heights)
        result = [n] * n
        stk = []
        for i in range(n):
            while stk and heights[i] < heights[stk[-1]]:
                result[stk[-1]] = i
                stk.pop()
            stk.append(i)
        return result

    def previous_smaller_index(self, heights):
        result = heights.copy()
        result.reverse()
        result = self.next_smaller_index(result)
        result.reverse()
        n = len(heights)
        for i in range(n):
            result[i] = n - result[i] - 1
        return result

    def square_area(self, heights):
        n = len(heights)
        prev = self.previous_smaller_index(heights)
        next = self.next_smaller_index(heights)
        area = 0
        for i in range(n):
            left = prev[i] + 1
            right = next[i] - 1
            side = min(heights[i], (right - left + 1))
            area = max(area, side * side)
        return area

    def maximalSquare(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        matrix2 = [[0] * cols for _ in range(rows)]
        for r in range(rows):
            for c in range(cols):
                matrix2[r][c] = int(matrix[r][c])
        self.prefixSumCol(matrix2)
        area = 0
        for r in range(rows):
            area = max(area, self.square_area(matrix2[r]))
        return area
