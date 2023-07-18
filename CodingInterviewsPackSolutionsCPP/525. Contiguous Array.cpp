class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cumSum = 0;
        unordered_map<int,int>myMap;
        myMap[0] = -1;
        int sz = nums.size();
        int result = 0;

        for(int i = 0; i < sz; i++){
            if(nums[i]==0)
                cumSum--;
            else
                cumSum++;

            if(!myMap.count(cumSum))
                myMap[cumSum] = i;
            else
                result = max(result,i-myMap[cumSum]);
        }
        return result;
    }
};
