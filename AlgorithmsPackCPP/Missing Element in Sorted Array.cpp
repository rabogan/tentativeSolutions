class Solution {
public:
    int missing(vector<int>&nums, int index){
        return nums[index]-nums[0]-index;
    }

    int kth(vector<int>&nums, int k, int index){
        return nums[index]+k-missing(nums,index);
    }

    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();

        if(missing(nums,n-1)<k)
            return kth(nums,k,n-1);

        int start = 0;
        int end = n-1;
        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;
            if(missing(nums,mid)<k){
                start = mid+1;
            }else{
                end = mid-1;
                ans = mid;
            }
        }
        return kth(nums,k,ans-1);
    }
};
