class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int sum = 0;
        int mnValue = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(k&&nums[i]<0){
                k--;
                nums[i]*=-1;                
            }
            mnValue = min(mnValue,nums[i]);
            sum+=nums[i];
        }
        if(k%2==1)
           sum-=2*mnValue;
        
        return sum;
    }
};