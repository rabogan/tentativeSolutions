const int MAX = 1000+1;
int LISmem[MAX];
int LDSmem[MAX];
vector<int>nums;
class Solution {
public:
    int LIS(int index){
        if(index==-1)
            return 0;
        auto&ret = LISmem[index];
        if(ret!=-1)
            return ret;
        ret = 0;
        for(int prev = index-1; prev>=0; prev--){
            if(nums[prev]<nums[index]){
                ret = max(ret,LIS(prev));
            }
        }
        ret+=1;
        return ret;
    }

    int LDS(int index){
        if(index>=nums.size())
            return 0;
        auto&ret = LDSmem[index];
        if(ret!=-1)
            return ret;
        ret = 0;
        for(int next = index+1; next < nums.size(); next++){
            if(nums[index]>nums[next])
                ret = max(ret,LDS(next));
        }
        ret+=1;
        return ret;
    }

    int minimumMountainRemovals(vector<int>& nums_) {
        nums = nums_;
        int n = nums.size();
        memset(LISmem,-1,sizeof(LISmem));
        memset(LDSmem,-1,sizeof(LDSmem));
        int mountains = 0;
        for(int i = 0; i < n; i++){
            if(LIS(i)==1 || LDS(i)==1)
                continue;

            int cur = LIS(i)+LDS(i)-1;
            mountains = max(mountains,cur);
        }
        return n-mountains;
    }
};
