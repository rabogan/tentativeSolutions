/*
A convoluted, but successful approach!

OUR GOAL:
We want to get the maximum area of 1s possible, and can/must use rearrangement of the
columns to do so.  Simply leaving the matrix as it is may not give the right solution

OUR SOLUTION:
1)  Take a look at how we can represent this matrix as a HISTOGRAM here:
https://leetcode.com/submissions/detail/804786323/
I used 'Next Smaller Element' rather than index (my mistake!)

The TLDR:
So, our rectangle area solution will find 2 vectors:
a)  vector<int>next (for the NEXT SMALLER INDEX)
b)  vector<int>prev (for the PREVIOUS SMALLER INDEX)
c)  We iterate through our heights, and calculate an INITIAL AREA for a rectangle at height[i]
d)  We maximize among these areas to get our result, returning (in my exemplar case) maxArea
We will SLICE UP the matrix, going from the top row to the bottom row, calculating areas!

2)  HOWEVER, we need to perform a special prefix sum calculation, so that the LOWER ROWS
are well represented.  The details about this are similar to LeetCode 85 (HERE):
https://leetcode.com/submissions/detail/804873331/
The TLDR:
a) Try EVERY row in our matrix, but as the base of a rectangle
b) Step ZERO: don't forget to return 0 if the matrix is 0
c)  Perform a special function, prefix_sum_column_variant, to change our integer matrix
into a histogram - can you see how they add up?
i.e.
1 0 1 0 1   -------\    1 0 1 0 1
1 0 1 1 1           \   2 0 2 1 2
1 1 1 1 0            >  3 1 3 2 0
1 0 0 1 1           /   4 0 0 3 1
0 0 1 0 0   -------/    0 0 1 0 2


3) BUT, we are allowed AND MUST sort out our rows, row by row, each time
This will coagulate all our largest values to the RIGHT HAND SIDE...e.g.
OUR PREFIX SUM ------>  OUR REARRANGED MATRIX
1 0 1 0 1   -------\    0 0 1 1 1
2 0 2 1 2           \   0 1 2 2 2
3 1 3 2 0            >  0 1 2 3 3
4 0 0 3 1           /   0 0 1 3 4
0 0 1 0 2   -------/    0 0 0 1 2
NOW, we send EACH ROW in the histogram as our VECTOR,
and insert it into the largestRectangleArea functions
Maximizing the area calculation should be relatively easy!
Can you visually observe our answer here??? 12!!! (4*3)--->plus row number 3 (0,1,2,3,4) into the functions to see why!
*/

class Solution {
public:
    void prefixSumCol(vector<vector<int>>&matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int c = 0; c < cols; c++){
            for(int r = 1; r < rows; r++){
                matrix[r][c]+=(matrix[r][c]!=0)*matrix[r-1][c];
            }
        }
    }
    
    vector<int>NSI(vector<int>&heights){  //Next Smallest INDEX
        int n = heights.size();
        vector<int>result(n, n);
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
    
    vector<int>PSI(const vector<int>& v) {  //Previous Smallest INDEX
        vector<int> res = v;
        reverse(res.begin(), res.end());
        res = NSI(res);
        reverse(res.begin(), res.end());
        int n = (int) res.size();
        for (int i = 0; i < n; ++i)
            res[i] = n - res[i] - 1;    // reverse values
        return res;        // res[i] = -1 if not found
    }
    
    int largestRectangleArea(vector<int>&heights){
        vector<int>next = NSI(heights);
        vector<int>prev = PSI(heights);
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int left = prev[i]+1;
            int right = next[i]-1;
            int area = heights[i]*(right-left+1);
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        prefixSumCol(matrix);
        int rows = matrix.size();
        int area = 0;
        for(int r = 0; r < rows; r++){
            sort(matrix[r].begin(),matrix[r].end());
            area = max(area,largestRectangleArea(matrix[r]));
        }
        return area;
    }
};