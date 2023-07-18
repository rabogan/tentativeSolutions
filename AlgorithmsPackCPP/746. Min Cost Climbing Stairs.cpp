const int MAX = 1000+1;
int memory[MAX];
vector<int>cost;

class Solution {
public:
    int climb(int index){
        if(index>=cost.size())
            return 0;
        
        auto&ret = memory[index];
        if(ret!=-1)
            return ret;
        
        int next = cost[index]+climb(index+1);
        int skip = cost[index]+climb(index+2);
        
        return ret=min(next,skip);
    }
    
    int minCostClimbingStairs(vector<int>& cost_) {
        cost = cost_;
        memset(memory,-1,sizeof(memory));
        return min(climb(0),climb(1));
    }
};