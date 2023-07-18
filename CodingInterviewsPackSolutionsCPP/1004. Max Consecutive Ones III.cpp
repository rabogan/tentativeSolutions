class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sz = nums.size();
        int result = 0;
        for(int start = 0, end = 0, zeroes = 0; end < sz; end++){
            zeroes+=nums[end]==0;
            while(zeroes>k)
                zeroes-=nums[start++]==0;
            result = max(result,end-start+1);
        }
        return result;
    }
};