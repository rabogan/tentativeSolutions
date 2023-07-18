class Solution {
public:
    struct Cell{
        int r;
        int c;
    };

    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};

    queue<Cell>q;

    bool isValid(int r, int c, vector<vector<int>>&grid){
        if(r<0||r>=grid.size())
            return false;
        if(c<0||c>=grid[0].size())
            return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>>&grid, int oldVal = 1, int newVal = 2){
        if(!isValid(r,c,grid)||grid[r][c]!=oldVal)
            return;

        grid[r][c]=newVal;
        q.push({r,c});

        for(int d = 0; d < 4; d++){
            dfs(r+dr[d],c+dc[d],grid,oldVal,newVal);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows && q.empty(); r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c]==1){
                    dfs(r,c,grid);
                    break;
                }
            }
        }

        int levels = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().r;
                int c = q.front().c;
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nr = r+dr[d];
                    int nc = c+dc[d];
                    if(!isValid(nr,nc,grid)||grid[nr][nc]==2||grid[nr][nc]==3)
                        continue;

                    if(grid[nr][nc]==1)
                        return levels;

                    q.push({nr,nc});
                    grid[nr][nc] = 3;
                }
            }
            levels++;
        }
        return levels;
    }
};