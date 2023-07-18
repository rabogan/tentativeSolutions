class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        myMap = {}
        myMap[0] = 1
        sz = len(nums)
        result = 0
        prefixSum = 0
        for i in range(sz):
            prefixSum += nums[i]
            if prefixSum - k in myMap:
                result += myMap[prefixSum - k]
            myMap[prefixSum] = myMap.get(prefixSum, 0) + 1
        return result
