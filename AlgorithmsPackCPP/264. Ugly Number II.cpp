class Solution {
    typedef long long ll;  //avoiding overflow
public:
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>>minHeap;
        minHeap.push(1);
        
        int nth = 0;
        ll mnValue;
        
        while(!minHeap.empty() && nth < n){
            nth+=1;
            mnValue = minHeap.top();
            while(!minHeap.empty()&&minHeap.top()==mnValue)
                minHeap.pop();
            
            minHeap.push(2*mnValue);
            minHeap.push(3*mnValue);
            minHeap.push(5*mnValue);
        }
        return mnValue;
    }
};