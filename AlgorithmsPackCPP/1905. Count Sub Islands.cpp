class Solution {
    bool isIsland{};
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    bool isValid(int r, int c, vector<vector<int>>&grid2){
        if(r<0||r>=grid2.size())
            return false;
        if(c<0||c>=grid2[0].size())
            return false;
        return true;
    }
public:
    void dfs(int r, int c, vector<vector<int>>&grid1,vector<vector<int>>&grid2){
        if(!isValid(r,c,grid2)||grid2[r][c]==0)
            return;
        
        if(!grid1[r][c]){
            isIsland = false;
            return;
        }
        grid2[r][c] = 0;
        
        for(int d = 0; d<4; d++){
            dfs(r+dr[d],c+dc[d],grid1,grid2);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int count = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c<cols; c++){
                if(grid2[r][c]){
                    isIsland = true;
                    dfs(r,c,grid1,grid2);
                    count+=isIsland;
                }
            }
        }
        return count;
    }
};