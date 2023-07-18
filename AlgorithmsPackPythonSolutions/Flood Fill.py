class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        
        def isValid(r: int, c: int, image: List[List[int]]) -> bool:
            if r < 0 or r >= len(image):
                return False
            if c < 0 or c >= len(image[0]):
                return False
            return True
        
        def dfs(r: int, c: int, image: List[List[int]], visited: List[List[bool]], oldColor: int, newColor: int) -> None:
            if not isValid(r, c, image) or image[r][c] != oldColor or visited[r][c]:
                return
            
            visited[r][c] = True
            image[r][c] = newColor
            
            for d in range(4):
                dfs(r + dr[d], c + dc[d], image, visited, oldColor, newColor)
        
        visited = [[False] * len(image[0]) for _ in range(len(image))]
        dfs(sr, sc, image, visited, image[sr][sc], newColor)
        
        return image
