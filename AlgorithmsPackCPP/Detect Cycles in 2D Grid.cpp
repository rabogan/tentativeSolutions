class Solution {
int dr[4]{-1,0,1,0};
int dc[4]{0,1,0,-1};
bool is_cycle;  
public:
bool isValid(int r, int c, vector<vector<char>>&grid){
    if(r < 0 || r >= grid.size())
        return false;
    if(c<0 || c>=grid[0].size())
        return false;
    return true;
}
/*
parent_row and parent_col are the 'node we come from', 
and we need them in this solution
*/
void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<bool>>&visited, char oldColor, int parent_row = -1, int parent_col = -1) 
{
    if(!isValid(r,c,grid) || grid[r][c]!=oldColor||is_cycle)
        return;
    
    if(visited[r][c]){
        is_cycle = true;
        return;
    }
    
    visited[r][c] = 1;
    
    for(int d = 0; d < 4; d++){   
        int nr = dr[d]+r;
        int nc = dc[d]+c;
         
        //THIS IS THE PARENT 'TRICK'.  We can't 'go back' to our parent.
        if(nr==parent_row && nc==parent_col)
            continue;
        
        dfs(nr,nc,grid,visited,oldColor,r,c);
    }
}

bool containsCycle(vector<vector<char>>& grid) {
    vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size()));
    int rows = grid.size();
    int cols = grid[0].size();        
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if(!visited[r][c]){ 
                is_cycle = false; 
                dfs(r,c,grid,visited,grid[r][c]);
                if(is_cycle)
                    return true;
            }
        }
    }
    return false;
};
