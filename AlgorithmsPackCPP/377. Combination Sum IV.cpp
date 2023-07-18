const int MAX = 5000+1;
int memory[MAX];
vector<int>nums;
class Solution {
public:
    int combi(int target){
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        
        auto&ret = memory[target];
        if(ret!=-1)
            return ret;
        
        ret=0;
        for(auto&value:nums)
            ret+=combi(target-value);
        return ret;
    }
    
    int combinationSum4(vector<int>& nums_, int target) {
        nums = nums_;
        memset(memory,-1,sizeof(memory));
        return combi(target);
    }
};