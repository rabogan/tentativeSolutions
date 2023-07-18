class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        sz = len(arr)
        
        minDiff = float('inf')
        for index in range(1, sz):
            minDiff = min(minDiff, arr[index] - arr[index-1])
        
        result = []
        for index in range(1, sz):
            if arr[index] - arr[index-1] == minDiff:
                result.append([arr[index-1], arr[index]])
        
        return result
