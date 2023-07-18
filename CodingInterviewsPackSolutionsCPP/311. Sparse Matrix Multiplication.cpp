/*
This is a somewhat tough (but secondary-school) math challenge.  To make up the result matrix,
we need to rows from matrix 1, and cols from matrix 2!

We know that 1 size (colsMatrix1 and rowsMatrix2) is common to both matrices...and can exploit it for our needs

We could iterate using
rows...cols...common_row...
This gives us an answer...but if we have a lot of zeroes, why not use the 'common' factor earlier in the loop, saving time?

for(int r = 0; r < rows; r++)
for(int k = 0; k < common; k++)
if(mat1[r][k])
---> THIS IS THE KEY!  If the mat1[r][k] value exists, GREAT!  We continue.  If not, we've shut down a complete loop
for(int c = 0; c < cols; c++)
matrix[r][c] += matrix1[r][k]*matrix2[k][c];
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int rows = mat1.size();
        int cols = mat2[0].size();
        int common = mat1[0].size();
        
        vector<vector<int>>result(rows,vector<int>(cols));
        
        for(int r = 0; r < rows; r++){
            for(int k = 0; k < common; k++){
                if(mat1[r][k])
                    for(int c = 0; c < cols; c++)
                        result[r][c]+=mat1[r][k]*mat2[k][c];
            }
        }
        return result;
    }
};