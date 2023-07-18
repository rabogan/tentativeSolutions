class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        MAX = 100 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        cubs = cuboids

        def lessEq(i, j):
            return cubs[i][1] <= cubs[j][1] and cubs[i][2] <= cubs[j][2]

        def height(cur, prev):
            if cur == len(cubs):
                return 0

            if memory[cur][prev] != -1:
                return memory[cur][prev]

            choice1 = height(cur + 1, prev)
            choice2 = 0

            if prev == len(cubs) or lessEq(prev, cur):
                choice2 = cubs[cur][2] + height(cur + 1, cur)

            memory[cur][prev] = max(choice1, choice2)
            return memory[cur][prev]

        for c in cuboids:
            c.sort()
        cuboids.sort()
        return height(0, len(cuboids))
