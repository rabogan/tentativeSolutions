class Solution {
public:
    int count(vector<int>&nums, int index){
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count+=((nums[i]+index-1)/index);
        }
        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;
            if(count(nums,mid)<=threshold){
                end = mid-1;
                ans = mid;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};