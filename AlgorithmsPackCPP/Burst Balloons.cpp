const int MAX = 300+2+1;
int memory[MAX][MAX];
vector<int>nums;

class Solution {
public:
    int coins(int start, int end){
        if(start>end)
            return 0;

        auto&ret = memory[start][end];
        if(ret!=-1)
            return ret;
        
        ret = INT_MIN;

        for(int split = start; split<=end; split++){
            int action = nums[start-1]*nums[split]*nums[end+1];
            int sub1 = coins(start,split-1);
            int sub2 = coins(split+1,end);
            int total = action+sub1+sub2;
            ret = max(ret,total);
        }
        return ret;
    }

    int maxCoins(vector<int>& nums_) {
        nums = nums_;
        memset(memory,-1,sizeof(memory));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return coins(1,nums.size()-2);
    }
};
