class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int result = INT_MIN;
        int maxSoFar = 0;
        
        for(int i = 0; i < sz; i++){
            maxSoFar = max(nums[i],nums[i]+maxSoFar);
            result = max(result,maxSoFar);
        }
        return result;
    }
};
