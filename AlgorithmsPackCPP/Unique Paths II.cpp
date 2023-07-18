const int MAX = 100+1;
int memory[MAX][MAX];
vector<vector<int>>grid;

class Solution {
public:
    int countWays(int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(r>=rows||c>=cols||grid[r][c]==1)
            return 0;
        
        if(rows-1==r && cols-1==c)
            return 1;
        
        auto&ret = memory[r][c];
        if(ret!=-1)
            return ret;
        
        int down = countWays(r+1,c);
        int right = countWays(r,c+1);
        
        return ret = down+right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        memset(memory,-1,sizeof(memory));
        return countWays(0,0);
    }
};
