class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]

        def isValid(r, c, heights):
            if r < 0 or r >= len(heights):
                return False
            if c < 0 or c >= len(heights[0]):
                return False
            return True

        def dfs(r, c, heights, visited, diff):
            if r == len(heights) - 1 and c == len(heights[0]) - 1:
                return True

            visited[r][c] = True

            for d in range(4):
                nr = dr[d] + r
                nc = dc[d] + c
                if not isValid(nr, nc, heights) or visited[nr][nc] or abs(heights[nr][nc] - heights[r][c]) > diff:
                    continue

                if dfs(nr, nc, heights, visited, diff):
                    return True

            return False

        def possible(heights, diff):
            rows = len(heights)
            cols = len(heights[0])
            visited = [[False] * cols for _ in range(rows)]

            return dfs(0, 0, heights, visited, diff)

        start = 0
        end = int(1e9)
        ans = end

        while start <= end:
            mid = start + (end - start) // 2
            if possible(heights, mid):
                end = mid - 1
                ans = mid
            else:
                start = mid + 1

        return ans
