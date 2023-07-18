class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        MAX = 500 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        str1 = word1
        str2 = word2

        def levenshtein(i, j):
            if i == -1 or j == -1:
                return max(i, j) + 1
            if memory[i][j] != -1:
                return memory[i][j]
            if str1[i] == str2[j]:
                return levenshtein(i - 1, j - 1)
            change = 1 + levenshtein(i - 1, j - 1)
            delete_ = 1 + levenshtein(i - 1, j)
            insert = 1 + levenshtein(i, j - 1)
            memory[i][j] = min(change, delete_, insert)
            return memory[i][j]

        return levenshtein(len(str1) - 1, len(str2) - 1)
