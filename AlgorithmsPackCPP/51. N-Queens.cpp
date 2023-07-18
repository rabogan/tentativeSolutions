/*
The solution for a notorious backtracking problem!
Observe how the diagonals will work!
ANTI-DIAG   NORM-DIAG
0 1 2 3 4   0 -1 -2 -3 -4
1 2 3 4 5   1 0 -1 -2 -3
2 3 4 5 6   2 1 0 -1 -2
3 4 5 6 7   3 2 1 0 -1
4 5 6 7 8   4 3 2 1 0
Basically, we want to avoid a situation where queens 'attack' each other
i.e. we want to avoid placing a queen 'Q' within our string of '.' when:
1) The column already has a Queen in it (i.e. column[c] = true)
2) The ANTI-DIAG has a Queen in it (see the 'x' calculation)
3) The NORM-DIAG has a Queen in it (see the 'y' calcualtion) 
4) ROWS are already assured of no queens, we're going row-by-row through the 'board' :)

Looking again at the tables above, observe what makes diagonal values equal
IN the ANTI-DIAG case, it's R+C
So, we'll use int x = r+c, and then make a condition such that antiDiag[x] must not be breached
In the NORM-DIAG case, it's n-1+r-c
So, using int y = n-1+r-c, we use a condition to check that normDiag[y] isn't breached

Our backtracking code itself is 5 lines, changing the cur[r][c] into 'Q', and also
changing the antiDiag[y], normDiag[x] and columns[c]
We run backtrack(r+1), then reverse.  Rinse and repeat for an O(N!) solution 
*/

class Solution {
    int n;
    vector<bool>normDiag;
    vector<bool>antiDiag;
    vector<bool>columns;
    vector<vector<string>>solution;
    vector<string>cur;
public:
    void backtrack(int r){
        if(r==n){
            solution.push_back(cur);
            return;
        }

        for(int c = 0; c < n; c++){
            int x = r+c;
            int y = n-1+r-c;

            if(columns[c]||normDiag[y]||antiDiag[x])
                continue;

            cur[r][c] = 'Q';
            columns[c] = normDiag[y] = antiDiag[x] = 1;

            backtrack(r+1);

            columns[c] = normDiag[y] = antiDiag[x] = 0;
            cur[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        normDiag = vector<bool>(2*n-1);
        antiDiag = vector<bool>(2*n-1);
        columns = vector<bool>(n);
        cur = vector<string>(n,string(n,'.'));
        backtrack(0);
        return solution;
    }
};