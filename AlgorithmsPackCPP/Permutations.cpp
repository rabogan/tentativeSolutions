vector<vector<int>>result;
vector<int>nums;

void permute_bt(int index){
    if(index==nums.size()){
        result.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++){
        swap(nums[i],nums[index]);
        permute_bt(index+1);
        swap(nums[i],nums[index]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums_) {
        nums = nums_;
        result.clear();
        permute_bt(0);
        return result;
    }
};

/*
We will permute all iterations/permutations for each index...
swapping the numbers each time
*/
