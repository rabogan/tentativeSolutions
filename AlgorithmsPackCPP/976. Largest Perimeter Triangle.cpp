class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i = 0; i < sz-2; i++){
            if(nums[i]<nums[i+1]+nums[i+2])
                return (nums[i]+nums[i+1]+nums[i+2]);
        }
        return 0;
    }
};