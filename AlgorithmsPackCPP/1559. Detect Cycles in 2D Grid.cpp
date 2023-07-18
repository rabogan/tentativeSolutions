class Solution {
int dr[4]{-1,0,1,0};
int dc[4]{0,1,0,-1};
bool is_cycle;  //Everything up here is standard.  The utility function, the d-array...this is a necessary thing!
public:
bool isValid(int r, int c, vector<vector<char>>&grid){
    if(r < 0 || r >= grid.size())
        return false;
    if(c<0 || c>=grid[0].size())
        return false;
    return true;
}

void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<bool>>&visited, char oldColor, int parent_row = -1, int parent_col = -1)  //The last two arguments are the 'node we are coming from'; aka the parent coordinates
{
    if(!isValid(r,c,grid) || grid[r][c]!=oldColor||is_cycle)  //is_cycle speeds up the process
        return;
    
    if(visited[r][c]){   //Basically, the 'is_cycle = true' is generatd by going back to our parent in a loop!  The 'directional array' calculation (and continue) below stops us from 'going back' to our parent. 
        is_cycle = true;
        return;
    }  //Is we have already visited it, we have looped back to it! (Return)
    
    visited[r][c] = 1;  //As standard in dfs, mark visited[r][c] as visited
    
    for(int d = 0; d < 4; d++){   
        int nr = dr[d]+r;   //Calculate the 'next' place in the series!  nr/nc
        int nc = dc[d]+c;
        
        if(nr==parent_row && nc==parent_col) //THIS IS THE PARENT 'TRICK'.  We can't 'go back' to our parent.  This ensures that if we encounter visited[r][c] (earlier), we are definitely looping to it; and not just going backwards into it!
            continue;
        
        dfs(nr,nc,grid,visited,oldColor,r,c);   //Recurse using dfs :)
    }
}

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size()));   //This is used as a signal to show if a set of coordinates have been visited (or not)
        int rows = grid.size();
        int cols = grid[0].size();        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(!visited[r][c]){   //This 'big IF' indicated that we have a NEW connected component to check out!
                    is_cycle = false;   //CRUCIAL!  is_cycle is initialised as false...
                    dfs(r,c,grid,visited,grid[r][c]);  //We perform dfs to see if a cycle is possible
                    if(is_cycle)
                        return true;  //...return true if 'is_cycle' survives the dfs
                }
            }
        }
        return false;  //...and false otherwise!
    }
};