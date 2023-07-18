class Solution:
    def prefix_sum_column_variant(self, matrix):
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
        n = len(heights)
        res = heights.copy()
        res.reverse()
        res = self.next_smaller_index(res)
        res.reverse()

        for i in range(n):
            res[i] = n - res[i] - 1

        return res

    def largest_rectangle(self, heights):
        next = self.next_smaller_index(heights)
        prev = self.previous_smaller_index(heights)
        maxArea = 0
        n = len(heights)

        for i in range(n):
            left = prev[i] + 1
            right = next[i] - 1
            area = heights[i] * (right - left + 1)
            maxArea = max(maxArea, area)

        return maxArea

    def maximalRectangle(self, matrix):
        if not matrix:
            return 0

        rows = len(matrix)
        cols = len(matrix[0])

        matrix2 = [[0] * cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols):
                matrix2[r][c] = int(matrix[r][c])

        self.prefix_sum_column_variant(matrix2)

        maxArea = 0

        for r in range(rows):
            maxArea = max(maxArea, self.largest_rectangle(matrix2[r]))

        return maxArea
