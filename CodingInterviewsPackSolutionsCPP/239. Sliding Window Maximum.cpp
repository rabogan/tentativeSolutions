/*
SOLUTION!
There are several very beneficial solutions, including use of a BBST (multiset) and an unordered_map/value frequency combo
This one presents an O(N) solution

1)  We need a linear data structure from which we can easily retrieve the maximum element - the deque is nice!
1b)  The idea is that we place elements into the deque in a decreasing sequence, such that dq[0] is the largest :)
2) We iterate from left->right.  The first check we make assumes k elements have already been entered into the deque
2b) If that's the case, we remove the front element IFF dq[0]==nums[i-k]
2c) Basically, if the front element hasn't already been removed, then we remove it
3) The while loop removes any USELESS values from the deque.  Basically, if we get a number larger than any that passed before it in the array,
then we need to pop_back() our element
4) Whatever else happens, we will be pushing the element into the dq
5) If i>-k-1, then we will always add the front of the deque to our result
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        
        for(int i = 0; i < nums.size(); i++){
            if(i>=k && dq[0]==nums[i-k])
                dq.pop_front();
            
            while(!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            
            dq.push_back(nums[i]);
            
            if(i>=k-1)
                result.push_back(dq[0]);
        }
        return result;
    }
};