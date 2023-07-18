const int MAX = 100+1;
int memory[MAX];
vector<int>nums;

class Solution {
public:
    int theft(int index){
        if(index>=nums.size())
            return 0;

        auto&ret = memory[index];
        if(ret!=-1)
            return ret;

        int leave = theft(index+1);
        int take = nums[index]+theft(index+2);

        return ret = max(leave,take);
    }

    int rob(vector<int>& nums_) {
        nums = nums_;
        memset(memory,-1,sizeof(memory));
        return theft(0);
    }
};