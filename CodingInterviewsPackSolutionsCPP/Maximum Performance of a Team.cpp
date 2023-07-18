class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9+7;
        vector<pair<int,int>>engineers;
        for(int i = 0; i < n; i++){
            engineers.push_back({efficiency[i],speed[i]});
        }
        
        sort(engineers.rbegin(),engineers.rend());
        
        long speedSum = 0;
        long ans = 0;
        
        priority_queue<int,vector<int>,greater<int>>mnHeap;
        
        for(int i = 0; i < engineers.size(); i++){
            int e = engineers[i].first;
            int s = engineers[i].second;
            
            speedSum+=s;
            mnHeap.push(s);
            
            if(mnHeap.size()>k){
                speedSum-=mnHeap.top();
                mnHeap.pop();
            }
            ans = max(ans,speedSum*e);
        }
        ans%=MOD;
        return ans;
    }
};
