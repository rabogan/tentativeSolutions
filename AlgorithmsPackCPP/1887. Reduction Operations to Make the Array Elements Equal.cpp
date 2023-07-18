class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int operations = 0;
        for(int i = 1; i < n; i++){
            if(nums[i]!=nums[i-1])
                operations+=i;
        }
        return operations;
    }
};