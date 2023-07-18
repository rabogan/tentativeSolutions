const int MAX = 50+1;
int rows;
int cols;
int moves;
int memory[MAX][MAX][MAX];
const int MOD = 1e9+7;
class Solution {
public:
    int count(int r, int c, int move){
        if(r<0||r>=rows ||c<0||c>=cols)
            return 1;
        
        if(move==moves)
            return 0;
        
        auto&ret = memory[r][c][move];
        if(ret!=-1)
            return ret;
        
        ret = count(r+1,c,move+1);
        
        ret+=count(r-1,c,move+1);
        ret%=MOD;
        
        ret+=count(r,c+1,move+1);
        ret%=MOD;
        
        ret+=count(r,c-1,move+1);
        ret%=MOD;
        
        return ret;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows = m;
        cols = n;
        moves = maxMove;
        memset(memory,-1,sizeof(memory));
        return count(startRow,startColumn,0);
    }
};