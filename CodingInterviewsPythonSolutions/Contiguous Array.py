class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        cumSum = 0
        myMap = {}
        myMap[0] = -1
        sz = len(nums)
        result = 0

        for i in range(sz):
            if nums[i] == 0:
                cumSum -= 1
            else:
                cumSum += 1

            if cumSum not in myMap:
                myMap[cumSum] = i
            else:
                result = max(result, i - myMap[cumSum])
        return result
