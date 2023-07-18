class Solution:
    def longestValidParentheses(self, s: str) -> int:
        sz = len(s)
        result = 0
        stk = [-1]

        for i in range(sz):
            if s[i] == '(':
                stk.append(i)
            else:
                stk.pop()

                if not stk:
                    stk.append(i)
                
                result = max(result, i - stk[-1])

        return result
