class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int>result(sz,0);
        stack<int>stk;
        for(int i = 0; i < sz; i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                result[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};
