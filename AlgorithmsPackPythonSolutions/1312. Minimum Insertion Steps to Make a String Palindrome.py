class Solution:
    def minInsertions(self, s: str) -> int:
        MAX = 500 + 1
        memory = [[-1] * MAX for _ in range(MAX)]
        str_len = len(s)

        def insertion(start, end):
            if start >= end:
                return 0

            if memory[start][end] != -1:
                return memory[start][end]

            if s[start] == s[end]:
                return insertion(start + 1, end - 1)

            insert_left = 1 + insertion(start + 1, end)
            insert_right = 1 + insertion(start, end - 1)

            memory[start][end] = min(insert_right, insert_left)
            return memory[start][end]

        return insertion(0, str_len - 1)
