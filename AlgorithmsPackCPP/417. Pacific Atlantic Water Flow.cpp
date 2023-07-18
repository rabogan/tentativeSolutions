class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    struct Cell{
        int r;
        int c;
    };
    
    bool isValid(int r, int c, vector<vector<int>>&heights){
        if(r<0||r>=heights.size())
            return false;
        if(c<0||c>=heights[0].size())
            return false;
        return true;
    }
public:
    void bfs(vector<vector<int>>&heights, vector<vector<bool>>&visited, vector<Cell>&starts){
        queue<Cell>q;
        for(auto&ce:starts){
            q.push(ce);
            visited[ce.r][ce.c] = true;
        }
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
            int r = q.front().r;
            int c = q.front().c;
            q.pop();
            
            for(int d= 0; d < 4; d++){
                int nr = r+dr[d];
                int nc = c+dc[d];
                if(!isValid(nr,nc,heights)||visited[nr][nc]||heights[nr][nc]<heights[r][c])
                    continue;
                
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>>atlanticGraph(rows,vector<bool>(cols));
        vector<vector<bool>>pacificGraph(rows,vector<bool>(cols));
        
        vector<Cell>atlanticStarts;
        vector<Cell>pacificStarts;
        
        for(int r = 0; r < rows; r++){
            atlanticStarts.push_back({r,cols-1});
            pacificStarts.push_back({r,0});
        }
        
        for(int c = 0; c < cols; c++){
            atlanticStarts.push_back({rows-1,c});
            pacificStarts.push_back({0,c});
        }
        
        bfs(heights,atlanticGraph,atlanticStarts);
        bfs(heights,pacificGraph,pacificStarts);
        
        vector<vector<int>>result;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(atlanticGraph[r][c] && pacificGraph[r][c]){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
};