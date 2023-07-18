class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1; i+1 < n; i+=2)
            swap(nums[i],nums[i+1]);
    }
};