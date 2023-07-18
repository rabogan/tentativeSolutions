class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sz = arr.size();
        
        int minDiff = INT_MAX;
        
        for(int index = 1; index < sz; index++){
            minDiff = min(minDiff,arr[index]-arr[index-1]);
        }
        
        vector<vector<int>>result;
        
        for(int index = 1; index < sz; index++){
            if(arr[index]-arr[index-1]==minDiff)
                result.push_back({arr[index-1],arr[index]});
        }
        return result;
    }
};
