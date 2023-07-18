class Solution {
    typedef long long LL;
    
    bool inRange(LL low, LL high, LL num){
        return low<=num && num<=high;
    }
    
    bool process(queue<LL>&q, vector<int>&visited, LL low, LL high, LL num){
        if(num>high)
            return false;
        
        if(inRange(low,high,num))
            visited.push_back(num);
        
        q.push(num);
        return true;
    }
    
    
public:
    vector<int> countSteppingNumbers(LL low, LL high) {
        queue<LL>q;
        vector<int>visited;
        
        if(inRange(low,high,0))
            visited.push_back(0);
        
        for(int i = 1; i <= 9; i++){
            if(inRange(low,high,i))
                visited.push_back(i);
            q.push(i);
        }
        
        for(int levels = 0, sz = q.size(); !q.empty(); ++levels, sz = q.size()){
            while(sz--){
                LL cur = q.front();
                q.pop();
                int digit = cur%10;
                
                if(digit!=0 && !process(q,visited,low,high,(cur*10)+digit-1))
                    break;
                if(digit!=9 && !process(q,visited,low,high,(cur*10)+digit+1))
                    break;
            }
        }
        
        return visited;
    }
};
