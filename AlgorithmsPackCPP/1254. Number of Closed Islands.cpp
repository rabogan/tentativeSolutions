/*
A 5 step process
Step 1:  Simply, set up your directional array and the 'isValid' utility function - this checks validity of row/column values
Step 2:  Note the bool 'touches boundary' is needed.   A node cannot be completely enclosed if on the boundary
The 'onBoundary' utility provides a nice way of showing if a node is touching the boundary
Step 3:  Our initial closedIslands function has 5 things initialised within (6 if counting the touches_boundary = false)
We set up a big 'CONNECTED COMPONENT IDS' structure, vector<vector<int>>CCIDS; this holds IDS of connected components
We also need a 'ccid' (cleverly incremented and sent to DFS), and a count.  We're 'counting' IFF our node is not touching the boundary
Step 4:  The DFS function takes in 5 things.   It starts off with an interesting condition.  Basically, 
We check for validity of the node coordinates, whether it has been visited or not (CCIDS[r][r]), and if it is a non connected component (grid[r][c]==1)
Step 5:  We check the 'onBoundary' function; turning the bool true if so.  Note how our 'main' function increments count IFF !(NOT)on_boundary!!!!
Step 6:  The rest of the DFS function is perfunctory.  We make our CCID[r][c] = ccid, and then call DFS recursively using our d-array.
*/


class Solution {
int dr[4]{-1,0,1,0};
int dc[4]{0,1,0,-1};

bool touches_boundary;

bool isValid(int r, int c, vector<vector<int>>&grid){
    if(r < 0 || r>=grid.size())
        return false;
    if(c < 0 || c>=grid[0].size())
        return false;
    return true;
}
    
bool onBoundary(int r, int c, vector<vector<int>>&grid){
    if(r == 0 || r==grid.size()-1)
        return true;
    if(c==0 ||c==grid[0].size()-1)
        return true;
    return false;
}

void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&CCIDS, int ccid){
    if(!isValid(r,c,grid) || CCIDS[r][c] ||grid[r][c]==1) // Meaning invalid, already visited, or NON-CC (a non connected component; grid[r][c]==1)
        return;
    
    if(onBoundary(r,c,grid))
        touches_boundary = true;
    
    CCIDS[r][c] = ccid;   //Assigns a specific ID to this CC
    for(int d = 0; d < 4; d++){
        dfs(r+dr[d],c+dc[d],grid,CCIDS,ccid);
    }
}    

public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>connectedComponentIDS(grid.size(),vector<bool>(grid[0].size()));
        int rows = grid.size();
        int cols = grid[0].size();
        int ccid = 0;
        int count = 0;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(!grid[r][c] && !connectedComponentIDS[r][c]){
                    touches_boundary = false;
                    dfs(r,c,grid,connectedComponentIDS,++ccid); //notice how we're incrementing the 'connected component id' each time
                    count+=!touches_boundary;
                }
            }
        }
        return count;
    }
};
