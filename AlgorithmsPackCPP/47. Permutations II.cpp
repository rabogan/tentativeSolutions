class Solution {
    vector<vector<int>>result;
    set<vector<int>>filter;
    vector<int>nums;

public:
    void backtrack(int index){
        if(index==nums.size()){
            filter.insert(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i],nums[index]);
            backtrack(index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums_) {
        nums = nums_;
        result.clear();
        backtrack(0);

        for(auto&v:filter)
            result.push_back(v);
        return result;
    }
};