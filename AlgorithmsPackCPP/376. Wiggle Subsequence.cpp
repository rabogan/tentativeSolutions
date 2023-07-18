class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 0, down = 0;
        for(int idx = 1; idx < nums.size(); idx++){
            if(nums[idx-1]<nums[idx])
                up = down+1;
            else if(nums[idx-1]>nums[idx])
                down = up+1;
        }
        return 1+max(up,down);
    }
};