const int MAX = 2500+1;
int memory[MAX];
vector<int>nums;

class Solution {
public:
    int LIS(int index){
        if(index>=nums.size())
            return 0;
        auto&ret = memory[index];
        if(ret!=-1)
            return ret;
        ret = 0;
        for(int next = index; next < nums.size(); next++){
            if(nums[index]<nums[next])
                ret = max(ret,LIS(next));
        }
        ret+=1;
        return ret;
    }

    int lengthOfLIS(vector<int>& nums_) {
        nums = nums_;
        nums.insert(nums.begin(),INT_MIN);
        memset(memory,-1,sizeof(memory));
        return LIS(0)-1;
    }
};