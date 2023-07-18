class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();
        int result = 0;
        stack<int>stk;
        stk.push(-1);

        for(int i = 0; i < sz; i++){
            if(s[i]=='(')
                stk.push(i);
            else{
                stk.pop();

                if(stk.empty())
                    stk.push(i);
                
                result = max(result,i-stk.top());
            }
        }
        return result;
    }
};