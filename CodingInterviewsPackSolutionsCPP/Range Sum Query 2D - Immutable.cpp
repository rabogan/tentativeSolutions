class NumMatrix {
    vector<vector<int>>accum;
public:
    void rowCumSum(){
        int rows = accum.size();
        int cols = accum[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 1; c < cols; c++){
                accum[r][c]+=accum[r][c-1];
            }
        }
    }
    
    void colCumSum(){
        int rows = accum.size();
        int cols = accum[0].size();
        for(int c = 0; c < cols; c++){
            for(int r = 1; r<rows; r++)
                accum[r][c]+=accum[r-1][c];
        }
    }
    
    NumMatrix(vector<vector<int>>& matrix):accum(matrix) {
        rowCumSum();
        colCumSum();
    }
    
    int cellSum(int r, int c){
        if(r<0||c<0)
            return 0;
        return accum[r][c];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cellSum(row2,col2)-cellSum(row2,col1-1)-cellSum(row1-1,col2)+cellSum(row1-1,col1-1);
    }
};
/*
0) First of all, to do this in O(1) time requires knowledge 
of IMAGE INTEGRAL!
1) Anyway, start by doing a cumulative sum by row...
2) Then cumulative sum by column! (take care with the loops)
These pre-computation steps take O(NM) time
3) There's a very clever computation, and you should sketch 
out the areas involved to understand it
Take the bottom corner (r2,c2)
Subtract from that value the cell left of the bottom left
Subtract from that value the cell above the top right
ADD the cell diagonally upper left of the top left
You're taking a BIG area, then subtracting two rectangles
(out of the left-most and upper-bounds) from it.
After that, you're ADDING the small upper-left area that 
you initially subtracted TWICE with the previous two operations
4) Use modular programming to help yourself as much as you can!
*/
