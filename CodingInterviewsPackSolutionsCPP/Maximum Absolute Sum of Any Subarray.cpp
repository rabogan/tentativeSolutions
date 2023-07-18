class Solution {
public:
    int maxArray(vector<int>&nums){
        int sz = nums.size();
        int maxSumUntilHere = 0;
        int result = INT_MIN;
        for(int idx = 0; idx < sz; idx++){
            maxSumUntilHere = max(0,maxSumUntilHere+nums[idx]);
            result = max(result,maxSumUntilHere);
        }
        return result;
    }
    
    int minArray(vector<int>&nums){
        int sz = nums.size();
        int minSumUntilHere = 0;
        int result = INT_MAX;
        for(int idx = 0; idx < sz; idx++){
            minSumUntilHere = min(0,minSumUntilHere+nums[idx]);
            result = min(minSumUntilHere,result);
        }
        return result;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(maxArray(nums)),abs(minArray(nums)));
    }
};
