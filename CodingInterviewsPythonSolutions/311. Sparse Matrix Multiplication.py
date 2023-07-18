class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        rows = len(mat1)
        cols = len(mat2[0])
        common = len(mat1[0])
        
        result = [[0] * cols for _ in range(rows)]
        
        for r in range(rows):
            for k in range(common):
                if mat1[r][k]:
                    for c in range(cols):
                        result[r][c] += mat1[r][k] * mat2[k][c]
        
        return result
