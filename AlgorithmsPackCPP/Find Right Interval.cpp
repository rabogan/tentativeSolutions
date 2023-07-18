class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int>startsToIndices;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            startsToIndices[intervals[i][0]]=i;
        }
        vector<int>result(n,-1);
        for(int i = 0; i < n; i++){
            auto iter = startsToIndices.lower_bound(intervals[i][1]);
            if(iter!=startsToIndices.end())
                result[i] = iter->second;
        }
        return result;
    }
};
