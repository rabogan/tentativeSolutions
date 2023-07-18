/*
3 Functions from this solution are covered in greater detail here:
https://leetcode.com/submissions/detail/804815630/  (LeetCode 84)

We want the AREA of a rectangle, and will use histograms to get it
The TLDR:
We will convert our matrix into a histogram integer matrix.
Each row in our new matrix will be used as the BASE to calculate the area of a rectangle

1)  Try EVERY row in our matrix, but as the base of a rectangle
2)  Step ZERO: don't forget to return 0 is the matrix is 0
3)  Firstly, convert the char matrix into an integer matrix.  Make a duplicate matrix for this!!!
4)  Perform a special function, prefix_sum_column_variant, to change our int matrix
into a histogram
i.e.
1 0 1 0 1   -------\    1 0 1 0 1
1 0 1 1 1           \   2 0 2 1 2
1 1 1 1 0            >  3 1 3 2 0
1 0 0 1 1           /   4 0 0 3 1
0 0 1 0 0   -------/    0 0 1 0 2

Each ROW in the histogram here^ will be used as the VECTOR; inserted into the largestRectangleArea problem
When all is set up (i.e. the 3 functions NSE, PSE and largest rectangle area), the area calculation should
be relatively easy!  That said, this code will take a long LONG time!
*/

class Solution {
public:
    void prefix_sum_column_variant(vector<vector<int>>&matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int c = 0; c < cols; c++){
            for(int r = 1; r < rows; r++){
                matrix[r][c]+=(matrix[r][c]!=0) * matrix[r-1][c];
            }
        }
    }
    
    vector<int>NSE(vector<int>&heights){
        int n = heights.size();
        vector<int>result(n,n);
        stack<int>stk;
        
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[i]<heights[stk.top()]){
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
    
    vector<int>PSE(vector<int>&heights){
        int n = heights.size();
        vector<int>res = heights;
        reverse(res.begin(),res.end());
        res = NSE(res);
        reverse(res.begin(),res.end());
        
        for(int i = 0; i < n; i++){
            res[i] = n-res[i]-1;
        }
        return res;
    }
    
    int largestRectangle(vector<int>&heights){
        vector<int>next = NSE(heights);
        vector<int>prev = PSE(heights);
        
        int maxArea = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            int left = prev[i]+1;
            int right = next[i]-1;
            int area = heights[i]*(right-left+1);
            maxArea = max(maxArea,area);
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>>matrix2(rows,vector<int>(cols));
        
        for(int r = 0; r < rows; r++){
            for(int c =0; c < cols; c++){
                matrix2[r][c] = matrix[r][c]-'0';
            }
        }
        
        prefix_sum_column_variant(matrix2);
        
        int maxArea = 0;
        
        for(int r = 0; r < rows; r++){
            maxArea = max(maxArea,largestRectangle(matrix2[r]));
        }
        
        return maxArea;
    }
};