class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        size = len(temperatures)
        result = [0] * size
        stk = []
        
        for i in range(size):
            while stk and temperatures[i] > temperatures[stk[-1]]:
                index = stk.pop()
                result[index] = i - index
            stk.append(i)
        
        return result
