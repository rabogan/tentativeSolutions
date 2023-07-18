class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mySet = set(nums)
        answer = 0
        
        for val in nums:
            if val - 1 in mySet:
                continue
            
            length = 0
            while val in mySet:
                length += 1
                val += 1
            
            answer = max(answer, length)
        
        return answer
