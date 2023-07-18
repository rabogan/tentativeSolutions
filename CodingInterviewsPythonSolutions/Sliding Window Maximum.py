class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        dq = deque()
        
        for i in range(len(nums)):
            if i >= k and dq[0] == nums[i - k]:
                dq.popleft()
            
            while dq and nums[i] > dq[-1]:
                dq.pop()
            
            dq.append(nums[i])
            
            if i >= k - 1:
                result.append(dq[0])
        
        return result
