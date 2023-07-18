class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        myMap = {}
        n = len(nums)
        for i in range(n):
            if nums[i] in myMap and i - myMap[nums[i]] <= k:
                return True
            myMap[nums[i]] = i
        return False
