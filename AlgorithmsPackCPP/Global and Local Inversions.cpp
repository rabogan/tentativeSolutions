class Solution {
public:
    vector<int>tmp;

    long long mergeSortedSubarrays(vector<int>&nums, int start, int mid, int end){
        long long globalConversions = 0;
        for(int i = start, j = mid+1, k = start; k<=end; k++){
            if(i>mid)
                tmp[k] = nums[j++];
            else if(j>end)
                tmp[k] = nums[i++];
            else if(nums[i]<nums[j])
                tmp[k] = nums[i++];
            else{
                tmp[k] = nums[j++];
                globalConversions+=mid-i+1;
            }
        }
        for(int i = start; i<=end; i++)
            nums[i] = tmp[i];
        return globalConversions;
    }

    long long mergeSort(vector<int>&nums, int start, int end){
        if(start==end)
            return 0;
        int mid = start+(end-start)/2;
        long long conv = mergeSort(nums,start,mid);
        conv+=mergeSort(nums,mid+1,end);
        conv+=mergeSortedSubarrays(nums,start,mid,end);
        return conv;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        tmp = nums;

        long long localInversions = 0;
        for(int i = 0; i < n-1; i++){
            localInversions+=(nums[i] > nums[i+1]);
        }

        long long globalInversions = mergeSort(nums,0,n-1);
        return globalInversions==localInversions;
    }
};
/*
Why do we do this?  Well, counting inversions helps to indicate 
the SORTEDNESS of the array!
1)  Calculating the local inversions is simple
2)  We call merge sort, which is excellent at counting 
global inversions
3 )  In side of merge sort, 3 processes occur:
3a)  We calculate the global inversions in the left subarray
3b)  We do the same for those in the right subarray
3c)  Finally, we call mergeSortedSubarrays, which returns 
the number of global inversions following the D&C calculation!
4) The mergeSortedSubarrays function itself is slightly 
tweaked from my own implementation of merge sort.  We do 
the usual inclusion of a temporary vector, but also use 
globalConversions = mid-i+1 - once we find a situation
where nums[j]>=nums[i]!
*/
