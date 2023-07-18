const int MAX = 100+1;
int memory[MAX][MAX];
vector<vector<int>>cubs;

class Solution {
public:
    bool lessEq(int i, int j){
        return cubs[i][1]<=cubs[j][1] && cubs[i][2]<=cubs[j][2];
    }
    
    int height(int cur, int prev){
        if(cur==cubs.size())
            return 0;
        
        auto&ret = memory[cur][prev];
        if(ret!=-1)
            return ret;
        
        int choice1 = height(cur+1,prev);
        int choice2 = 0;
        
        if(prev==cubs.size()||lessEq(prev,cur))
            choice2 = cubs[cur][2]+height(cur+1,cur);
        
        return ret = max(choice1,choice2);
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto&c:cuboids)
            sort(c.begin(),c.end());
        sort(cuboids.begin(),cuboids.end());
        memset(memory,-1,sizeof(memory));
        cubs = cuboids;
        return height(0,cuboids.size());
    }
};