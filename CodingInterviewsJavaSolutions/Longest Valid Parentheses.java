class Solution {
    public int longestValidParentheses(String s) {
        int sz = s.length();
        int result = 0;
        Stack<Integer> stk = new Stack<>();
        stk.push(-1);

        for (int i = 0; i < sz; i++) {
            if (s.charAt(i) == '(')
                stk.push(i);
            else {
                stk.pop();

                if (stk.empty())
                    stk.push(i);

                result = Math.max(result, i - stk.peek());
            }
        }
        return result;
    }
}
