class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = INT_MIN;
        int n = nums.size();
        int maxSoFar = nums.back();
        for(int i = n-2; i >=0; i--){
            if(nums[i]<maxSoFar)
                result = max(result,maxSoFar-nums[i]);

            maxSoFar = max(maxSoFar,nums[i]);
        }
        if(result==INT_MIN)
            return -1;
        return result;
    }
};
