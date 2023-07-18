class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>myMap;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(myMap.count(nums[i]) && i-myMap[nums[i]]<=k)
                return true;

            myMap[nums[i]] = i;
        }
        return false;
    }
};
