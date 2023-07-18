class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    bool isValid(int r, int c, vector<vector<int>>&heights){
        if(r<0||r>=heights.size())
            return false;
        if(c<0||c>=heights[0].size())
            return false;
        return true;
    }
public:
    bool dfs(int r, int c, vector<vector<int>>&heights,vector<vector<bool>>&visited, int diff){
        if(r==heights.size()-1 && c==heights[0].size()-1)
            return true;
        
        visited[r][c] = true;
        
        for(int d =0; d < 4; d++){
            int nr = dr[d]+r;
            int nc = dc[d]+c;
            if(!isValid(nr,nc,heights)||visited[nr][nc]||abs(heights[nr][nc]-heights[r][c])>diff)
                continue;
            
            if(dfs(nr,nc,heights,visited,diff))
                return true;
        }
        return false;
    }
    
    bool possible(vector<vector<int>>&heights, int diff){
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols));
        
        return dfs(0,0,heights,visited,diff);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int start = 0;
        int end = 1e9;
        int ans = end;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(possible(heights,mid)){
                end = mid-1;
                ans = mid;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};