class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    bool isValid(int r, int c, vector<vector<int>>&image){
        if(r < 0 || r >= image.size())
            return false;
        if(c < 0 || c>=image[0].size())
            return false;
        return true;
    }
public:
    void dfs(int r, int c, vector<vector<int>>&image, vector<vector<bool>>&visited, int oldColor, int newColor){
        if(!isValid(r,c,image) || image[r][c]!=oldColor || visited[r][c])
            return;
        
        visited[r][c] = true;
        
        image[r][c] = newColor;
        
        for(int d = 0; d < 4; d++){
            dfs(r+dr[d],c+dc[d],image,visited,oldColor,newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size()));
        dfs(sr,sc,image,visited,image[sr][sc],newColor);
        return image;
    }
};
