const int MAX = 100+1;
int memory[MAX][MAX];
vector<vector<int>>matrix;

class Solution {
public:
    int fallingSum(int r, int c){
        int rows = matrix.size();
        int cols = matrix[0].size();

        if(c<0||c>=cols)
            return INT_MAX/2;

        if(r==rows-1)
            return matrix[r][c];

        auto&ret = memory[r][c];
        if(ret!=-1)
            return ret;

        int dl = fallingSum(r+1,c-1);
        int down = fallingSum(r+1,c);
        int dr = fallingSum(r+1,c+1);

        return ret = matrix[r][c]+min(dl,min(down,dr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix_) {
        matrix = matrix_;
        memset(memory,-1,sizeof(memory));
        int sum = INT_MAX;
        for(int c = 0; c < matrix[0].size(); c++)
            sum = min(sum,fallingSum(0,c));
        return sum;
    }
};