class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        isIsland = False
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        
        def isValid(r: int, c: int, grid: List[List[int]]) -> bool:
            if r < 0 or r >= len(grid):
                return False
            if c < 0 or c >= len(grid[0]):
                return False
            return True
        
        def dfs(r: int, c: int, grid1: List[List[int]], grid2: List[List[int]]) -> None:
            nonlocal isIsland
            
            if not isValid(r, c, grid2) or grid2[r][c] == 0:
                return
            
            if not grid1[r][c]:
                isIsland = False
                return
            
            grid2[r][c] = 0
            
            for d in range(4):
                dfs(r + dr[d], c + dc[d], grid1, grid2)
        
        rows = len(grid2)
        cols = len(grid2[0])
        count = 0
        
        for r in range(rows):
            for c in range(cols):
                if grid2[r][c]:
                    isIsland = True
                    dfs(r, c, grid1, grid2)
                    count += isIsland
        
        return count
