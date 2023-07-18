class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        MAX = 200 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        dungeon = dungeon
        OO = int(1e9)

        def minHealth(r, c):
            rows = len(dungeon)
            cols = len(dungeon[0])

            if r >= rows or c >= cols:
                return OO

            if r == rows - 1 and c == cols - 1:
                if dungeon[r][c] < 0:
                    return 1 - dungeon[r][c]
                return 1

            if memory[r][c] != -1:
                return memory[r][c]

            health = min(minHealth(r + 1, c), minHealth(r, c + 1))

            if health <= dungeon[r][c]:
                return 1

            ret = health - dungeon[r][c]
            memory[r][c] = ret
            return ret

        return minHealth(0, 0)
