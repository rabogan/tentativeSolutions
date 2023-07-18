const int MOD = 1e9+7;
const int MAX = 30+1;
const int MAX_T = 1000+1;
int dice;
int rolls;
int memory[MAX][MAX_T];

class Solution {
public:
    int rolling(int index, int target){
        if(target<0)
            return 0;
        if(index==dice && target==0)
            return 1;
        if(index==dice||target==0)
            return 0;
        auto&ret = memory[index][target];
        if(ret!=-1)
            return ret;
        
        ret = 0;
        for(int f = 1; f<=rolls; f++){
            ret+=rolling(index+1,target-f);
            ret%=MOD;
        }
        return ret;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dice = n;
        rolls = k;
        memset(memory,-1,sizeof(memory));
        return rolling(0,target);
    }
};
