class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(int idx = 0; idx < points.size(); idx++){
            vector<int>loc = {points[idx][0],points[idx][1]};
            int dist = loc[0]*loc[0] + loc[1]*loc[1];
            
            if(maxHeap.size()<k||dist<maxHeap.top().first)
                maxHeap.push({dist,loc});
            
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
        vector<vector<int>>result;
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
