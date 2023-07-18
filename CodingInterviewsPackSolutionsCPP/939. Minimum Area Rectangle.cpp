class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>>x_to_ys;
        int sz = points.size();
        int ans = INT_MAX;
        
        for(int i = 0; i < sz; i++)
            x_to_ys[points[i][0]].insert(points[i][1]);
        
        for(int i = 0; i < sz; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j = i+1; j < sz; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(x1==x2||y1==y2)
                    continue;
                
                if(!x_to_ys[x1].count(y2)||!x_to_ys[x2].count(y1))
                    continue;
                
                int area = abs(x2-x1)*abs(y2-y1);
                ans = min(ans,area);
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};
