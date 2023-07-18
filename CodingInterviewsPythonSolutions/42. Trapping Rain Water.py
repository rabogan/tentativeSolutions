class Solution:
    def trap(self, height: List[int]) -> int:
        sz = len(height)
        mxIndex = 0
        for i in range(1, sz):
            if height[i] > height[mxIndex]:
                mxIndex = i
        
        maxLeft = 0
        maxRight = 0
        answer = 0
        
        for i in range(mxIndex):
            maxLeft = max(maxLeft, height[i])
            answer += maxLeft - height[i]
        
        for i in range(sz - 1, mxIndex, -1):
            maxRight = max(maxRight, height[i])
            answer += maxRight - height[i]
        
        return answer
