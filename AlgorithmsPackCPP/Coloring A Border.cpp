class Solution {
public:
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};

    bool isValid(int r, int c, vector<vector<int>>&grid){
        if(r<0||r>=grid.size())
            return false;
        if(c<0||c>=grid[0].size())
            return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&visited, int color){
        if(!isValid(r,c,grid)||visited[r][c]||grid[r][c]!=color)
            return;

        visited[r][c] = true;

        for(int d = 0; d < 4; d++){
            dfs(r+dr[d],c+dc[d],grid,visited,color);
        }
    }

    void colorIn(vector<vector<int>>&grid, vector<vector<bool>>&visited, int color){
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                for(int d = 0; d < 4; d++){
                    if(!visited[r][c])
                        continue;

                    int nr = dr[d]+r;
                    int nc = dc[d]+c;

                    if(!isValid(nr,nc,grid)||!visited[nr][nc])
                        grid[r][c] = color;
                }
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols));
        dfs(row,col,grid,visited,grid[row][col]);
        colorIn(grid,visited,color);
        return grid;
    }
};
