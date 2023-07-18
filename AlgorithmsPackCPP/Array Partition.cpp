class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int sz = nums.size();
        for(int i = 0; i<sz; i+=2)
            sum+=nums[i];
        return sum;
    }
};
