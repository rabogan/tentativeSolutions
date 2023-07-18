class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz =  nums.size();
        int expectedSum = sz*(sz-1)/2;
        int actualSum = 0;
        
        for(int i = 0; i < sz; i++)
            actualSum+=nums[i];
        
        if(actualSum==expectedSum)
            return sz;
        return expectedSum-actualSum+sz;
    }
};
