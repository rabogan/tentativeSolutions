class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        int sz = nums.size();

        for(int i = 0; i < sz; i++){
            if(minHeap.size()<=k||nums[i]>minHeap.top()){
                minHeap.push(nums[i]);
            }

            if(minHeap.size()>k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};