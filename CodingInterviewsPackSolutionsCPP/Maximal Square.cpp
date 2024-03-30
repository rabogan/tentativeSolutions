class Solution {  
public:
    void prefixSumCol(vector<vector<int>>&matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int c = 0; c<cols;c++){
            for(int r = 1; r < rows; r++){
                matrix[r][c]+=(matrix[r][c]!=0)*matrix[r-1][c];
            }
        }
    }
    
    vector<int>NSI(vector<int>&heights){
        int n = heights.size();
        vector<int>result(n,n);
        stack<int>stk;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
    
    vector<int>PSI(vector<int>&heights){
        vector<int>result = heights;
        reverse(result.begin(),result.end());
        result = NSI(result);
        reverse(result.begin(),result.end());
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            result[i] = n-result[i]-1;
        }
        return result;
    }
    
    int squareArea(vector<int>&heights){
        int n = heights.size();
        vector<int>prev = PSI(heights);
        vector<int>next = NSI(heights);
        int area = 0;
        
        for(int i = 0; i < n; i++){
            int left = prev[i]+1;
            int right = next[i]-1;
            int side = min(heights[i],(right-left+1));
            area = max(area,side*side);
        }
        return area;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>matrix2(rows,vector<int>(cols));
        for(int r = 0; r < rows; r++){
            for(int c =0; c < cols; c++){
                matrix2[r][c] = matrix[r][c]-'0';
            }
        }
        prefixSumCol(matrix2);
        
        int area = 0;
        
        for(int r = 0; r < rows; r++){
            area = max(area,squareArea(matrix2[r]));
        }
        
        return area;
    }
};
/*
The NON-DP solution is presented here :)
Take a look at the maximal rectangle solution.....
https://leetcode.com/submissions/detail/804873331/
    
However, because we STRICTLY want a SQUARE area, our area 
function needs tweaking!  Basically, for any given LENGTH 
or HEIGHT (at a spot in our accumulated sum slice of a matrix),
we look for whatever the MINIMUM value among the length 
(right-left+1) and height (heights[i]) would be. 
Our height comes from the histogram, and the length from 
the next/prev smaller index functions
*/
