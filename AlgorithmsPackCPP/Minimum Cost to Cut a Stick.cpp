const int MAX = 100+1+2;
vector<int>cuts;
int memory[MAX][MAX];
class Solution {
public:
    int cost(int start, int end){
        if(start+1==end)
            return 0;
        
        auto&ret = memory[start][end];
        if(ret!=-1)
            return ret;
        
        ret = INT_MAX;
        
        for(int split = start+1; split<end; split++){
            int left = cost(start,split);
            int right = cost(split,end);
            int diff = cuts[end]-cuts[start];
            int total = left+right+diff;
            ret = min(ret,total);
        }
        return ret;
    }
    
    int minCost(int n, vector<int>& cuts_) {
        cuts = cuts_;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(memory,-1,sizeof(memory));
        return cost(0,cuts.size()-1);
    }
};
