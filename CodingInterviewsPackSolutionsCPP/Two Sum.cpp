class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>sumMap;
        int sz =nums.size();
        for(int index = 0; index < sz; index++){
            int remainder = target-nums[index];
            if(sumMap.count(remainder))
                return{sumMap[remainder], index};
            
            sumMap[nums[index]] = index;
        }
        return {-1,-1};
    }
};
