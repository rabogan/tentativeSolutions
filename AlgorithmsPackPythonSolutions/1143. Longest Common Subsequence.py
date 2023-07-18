class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        MAX = 1000 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        word1 = text1
        word2 = text2

        def LCS(i, j):
            if i >= len(word1) or j >= len(word2):
                return 0
            if memory[i][j] != -1:
                return memory[i][j]
            if word1[i] == word2[j]:
                return 1 + LCS(i + 1, j + 1)

            insertLeft = LCS(i + 1, j)
            insertRight = LCS(i, j + 1)

            memory[i][j] = max(insertLeft, insertRight)
            return memory[i][j]

        return LCS(0, 0)
