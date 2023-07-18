class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(int i = 0; i < nums.size(); i++){
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);

            if(maxHeap.size()>2)
                maxHeap.pop();

            if(minHeap.size()>3)
                minHeap.pop();
        }

        int max1, max2, max3, min1, min2;
        min2 = maxHeap.top();
        maxHeap.pop();
        min1 = maxHeap.top();
        maxHeap.pop();
        max3 = minHeap.top();
        minHeap.pop();
        max2 = minHeap.top();
        minHeap.pop();
        max1 = minHeap.top();
        minHeap.pop();

        return max(min1*min2*max1,max1*max2*max3);
    }
};