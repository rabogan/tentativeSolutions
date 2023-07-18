class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        set<vector<int>>filter;
        
        for(int i = 0; i <= n-4; i++){
            for(int j = i+1; j<=n-3; j++){
                int left = j+1;
                int right = n-1;
                
                while(left<right){
                    long long sum = nums[i] + nums[j];
                    sum += nums[left];
                    sum += nums[right] - target;
                    if(!sum){
                        vector<int>v({nums[i],nums[j],nums[left],nums[right]});
                        sort(v.begin(),v.end());
                        if(filter.insert(v).second)
                            result.push_back(v);
                        left++;
                        right--;
                    }else if(sum>0)
                        right--;
                    else
                        left++;
                }
            }
        }
        return result;
    }
};
