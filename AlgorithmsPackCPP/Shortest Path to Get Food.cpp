class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    bool isValid(int r, int c, vector<vector<char>>&grid){
        if(r<0||r>=grid.size())
            return false;
        if(c<0||c>=grid[0].size())
            return false;
        return true;
    }
    
    struct Cell{
        int r;
        int c;
    };
public:
    int bfs(vector<vector<char>>&grid, vector<vector<bool>>&visited, Cell start){
        queue<Cell>q;
        q.push(start);
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int r = q.front().r;
                int c = q.front().c;
                q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nr = dr[d]+r;
                    int nc = dc[d]+c;
                    if(!isValid(nr,nc,grid)||visited[nr][nc]||grid[nr][nc]=='X')
                        continue;
                    
                    if(grid[nr][nc]=='#')
                        return level+1;
                    
                    visited[nr][nc] = true;
                    if(grid[nr][nc]=='O')
                        q.push({nr,nc});
                }
            }
        }
        return -1;
    }
    
    
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        Cell start;
        
        vector<vector<bool>>visited(rows,vector<bool>(cols));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c]=='*'){
                    start = {r,c};
                    visited[r][c] = true;
                    break;
                }
            }
        }
        
        return bfs(grid,visited,start);
    }
};
