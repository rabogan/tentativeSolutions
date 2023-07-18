class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        MAX = 500 + 1
        memory = [-1] * MAX

        def partition(start):
            if start == len(arr):
                return 0

            if memory[start] != -1:
                return memory[start]

            result = float('-inf')
            max_value = float('-inf')

            for split in range(start, start + k):
                if split >= len(arr):
                    break
                max_value = max(max_value, arr[split])
                length = split - start + 1
                result = max(result, length * max_value + partition(split + 1))

            memory[start] = result
            return result

        return partition(0)
