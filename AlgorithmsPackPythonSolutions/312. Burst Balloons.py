class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        MAX = 300 + 2 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        nums.insert(0, 1)
        nums.append(1)

        def coins(start, end):
            if start > end:
                return 0

            if memory[start][end] != -1:
                return memory[start][end]

            result = float('-inf')
            for split in range(start, end + 1):
                action = nums[start - 1] * nums[split] * nums[end + 1]
                sub1 = coins(start, split - 1)
                sub2 = coins(split + 1, end)
                total = action + sub1 + sub2
                result = max(result, total)

            memory[start][end] = result
            return result

        return coins(1, len(nums) - 2)
