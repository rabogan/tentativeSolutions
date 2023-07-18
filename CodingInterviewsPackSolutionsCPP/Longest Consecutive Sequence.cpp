class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sz = nums.size();
        unordered_set<int>mySet;
        for(int i = 0; i < sz; i++)
            mySet.insert(nums[i]);
        
        int answer = 0;
        for(int val:nums){
            if(mySet.count(val-1))
                continue;
            
            int len = 0;
            while(mySet.count(val)){
                len++;
                val++;
            }
            answer = max(answer,len);
        }
        return answer;
    }
};
