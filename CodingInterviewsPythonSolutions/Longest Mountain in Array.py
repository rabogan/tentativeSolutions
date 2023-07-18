class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        sz = len(arr)
        result = up = down = 0
        index = 1
        
        while index < sz:
            if (down and arr[index - 1] < arr[index]) or arr[index - 1] == arr[index]:
                up = down = 0
            
            if arr[index - 1] < arr[index]:
                up += 1
            elif arr[index - 1] > arr[index]:
                down += 1
            else:
                up = 0
            
            if up and down:
                result = max(result, up + down + 1)
            
            index += 1
        
        return result
