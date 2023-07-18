class Solution:
    def prefixSumCol(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0])
        
        for c in range(cols):
            for r in range(1, rows):
                matrix[r][c] += (matrix[r][c] != 0) * matrix[r-1][c]
    
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
        res = heights[::-1]
        res = self.next_smaller_index(res)
        res = res[::-1]
        n = len(res)
        for i in range(n):
            res[i] = n - res[i] - 1
        return res
    
    def largestRectangleArea(self, heights):
        next_index = self.next_smaller_index(heights)
        prev_index = self.previous_smaller_index(heights)
        n = len(heights)
        maxArea = 0
        
        for i in range(n):
            left = prev_index[i] + 1
            right = next_index[i] - 1
            area = heights[i] * (right - left + 1)
            maxArea = max(area, maxArea)
        
        return maxArea
    
    def largestSubmatrix(self, matrix):
        self.prefixSumCol(matrix)
        rows = len(matrix)
        area = 0
        
        for r in range(rows):
            matrix[r].sort()
            area = max(area, self.largestRectangleArea(matrix[r]))
        
        return area
