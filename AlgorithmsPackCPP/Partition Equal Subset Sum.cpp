const int MAX = 200+1;
const int MAX_T = 100*200+1;
int memory[MAX][MAX_T];
vector<int>numms;

class Solution {
public:
    bool partition(int index, int target){
        if(target<0)
            return false;
        
        if(target==0)
            return true;
        
        if(index>=numms.size())
            return false;
        
        auto&ret = memory[index][target];
        if(ret!=-1)
            return ret;
        
        if(partition(index+1,target))
            return ret = true;
        
        return ret = partition(index+1,target-numms[index]);
    }
    
    bool canPart(vector<int>nums, int target){
        numms = nums;
        memset(memory,-1,sizeof(memory));
        return partition(0,target);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum+=nums[i];
        
        if(sum%2==1)
            return false;
        
        return canPart(nums,sum/2);
    }
};
