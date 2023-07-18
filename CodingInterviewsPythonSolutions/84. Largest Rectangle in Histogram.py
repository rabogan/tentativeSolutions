class Solution:
    def next_smaller_element(self, heights: List[int]) -> List[int]:
        n = len(heights)
        result = [n] * n
        stk = []
        
        for i in range(n):
            while stk and heights[i] < heights[stk[-1]]:
                result[stk[-1]] = i
                stk.pop()
            stk.append(i)
        
        return result
    
    def previous_smaller_element(self, heights: List[int]) -> List[int]:
        res = heights[::-1]
        res = self.next_smaller_element(res)
        res = res[::-1]
        n = len(res)
        for i in range(n):
            res[i] = n - res[i] - 1
        return res
    
    def largestRectangleArea(self, heights: List[int]) -> int:
        next = self.next_smaller_element(heights)
        prev = self.previous_smaller_element(heights)
        sz = len(heights)
        maxArea = 0
        
        for i in range(sz):
            left = prev[i] + 1
            right = next[i] - 1
            area = heights[i] * (right - left + 1)
            maxArea = max(area, maxArea)
        
        return maxArea
