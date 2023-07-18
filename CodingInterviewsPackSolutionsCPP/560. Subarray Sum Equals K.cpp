class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>myMap;
        myMap[0] = 1;
        int sz = nums.size();
        int result = 0;
        int prefixSum = 0;
        for(int i = 0; i < sz; i++){
            prefixSum+=nums[i];
            if(myMap.count(prefixSum-k))
                result+=myMap[prefixSum-k];
            
            myMap[prefixSum]++;
        }
        return result;
    }
};
