class Solution {
public:
    int summed(vector<int>&nums){
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++)
            total+=nums[i];
        return total;
    }

    int minArray(vector<int>&nums){
        int n = nums.size();
        int result = INT_MAX;
        int minSoFar = 0;
        for(int i = 0; i < n; i++){
            minSoFar = min(minSoFar+nums[i],nums[i]);
            result = min(result,minSoFar);
        }
        return result;
    }

    int maxArray(vector<int>&nums){
        int n = nums.size();
        int result = INT_MIN;
        int maxSoFar = 0;
        for(int i = 0; i < n; i++){
            maxSoFar = max(maxSoFar+nums[i],nums[i]);
            result = max(result,maxSoFar);
        }
        return result;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = summed(nums);
        int mn = minArray(nums);
        int mx = maxArray(nums);
        if(sum==mn)
            return mx;
        return max(mx,sum-mn);
    }
};
