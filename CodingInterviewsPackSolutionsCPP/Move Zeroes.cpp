class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        for(int start = 0, end = 0; end < sz; end++){
            if(nums[end]!=0)
                swap(nums[start++],nums[end]);
        }
    }
};
