class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        result = []
        filter_set = set()
        
        for i in range(n - 3):
            for j in range(i + 1, n - 2):
                left = j + 1
                right = n - 1
                
                while left < right:
                    sum_val = nums[i] + nums[j] + nums[left] + nums[right] - target
                    
                    if sum_val == 0:
                        quad = [nums[i], nums[j], nums[left], nums[right]]
                        quad.sort()
                        
                        if tuple(quad) not in filter_set:
                            result.append(quad)
                            filter_set.add(tuple(quad))
                        
                        left += 1
                        right -= 1
                    elif sum_val > 0:
                        right -= 1
                    else:
                        left += 1
        
        return result
