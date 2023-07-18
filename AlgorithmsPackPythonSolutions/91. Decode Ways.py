class Solution:
    def numDecodings(self, s: str) -> int:
        MAX = 100 + 1
        memory = [-1] * MAX
        str_length = len(s)

        def can_2_digit(index):
            if index + 1 >= str_length:
                return False
            if s[index] == '1':
                return True
            return s[index] == '2' and s[index + 1] <= '6'

        def count_ways(index):
            if index == str_length:
                return 1
            if s[index] == '0':
                return 0
            if memory[index] != -1:
                return memory[index]
            result = count_ways(index + 1)
            if can_2_digit(index):
                result += count_ways(index + 2)
            memory[index] = result
            return result

        return count_ways(0)
