class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = equal_range(nums.begin(),nums.end(),target);
        
        if(p.first==nums.end())
            return {-1,-1};
        
        int first = p.first-nums.begin();
        int second = p.second-nums.begin();
        
        if(nums[first]!=target)
            return{-1,-1};
        
        return {first,second-1};
    }
};
