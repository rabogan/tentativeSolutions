class Solution:
    def isValid(self, i: int, j: int, memory: List[List[int]], s: str) -> bool:
        if i >= j:
            return True
        
        if memory[i][j] != -1:
            return memory[i][j]
        
        if s[i] == s[j]:
            ret = self.isValid(i + 1, j - 1, memory, s)
            memory[i][j] = ret
            return ret
        
        memory[i][j] = False
        return False
    
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        memory = [[-1] * n for _ in range(n)]
        length = 0
        startIndex = 0
        
        for i in range(n):
            for j in range(i, n):
                len_ji = j - i + 1
                if self.isValid(i, j, memory, s) and len_ji > length:
                    length = len_ji
                    startIndex = i
        
        return s[startIndex:startIndex + length]
