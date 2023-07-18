class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sumMap = {}
        for index, num in enumerate(nums):
            remainder = target - num
            if remainder in sumMap:
                return [sumMap[remainder], index]
            
            sumMap[num] = index
        return [-1, -1]
