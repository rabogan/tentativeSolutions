class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        MAX = 100 + 1 + 2
        memory = [[-1] * MAX for _ in range(MAX)]
        cuts.append(0)
        cuts.append(n)
        cuts.sort()

        def cost(start, end):
            if start + 1 == end:
                return 0

            if memory[start][end] != -1:
                return memory[start][end]

            result = float('inf')
            for split in range(start + 1, end):
                left = cost(start, split)
                right = cost(split, end)
                diff = cuts[end] - cuts[start]
                total = left + right + diff
                result = min(result, total)

            memory[start][end] = result
            return result

        return cost(0, len(cuts) - 1)
