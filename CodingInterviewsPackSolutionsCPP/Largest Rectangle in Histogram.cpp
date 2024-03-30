class Solution {
public:
    vector<int>next_smaller_element(vector<int>&heights){
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
    
    vector<int>previous_smaller_element(vector<int>&heights){
        vector<int>res = heights;
        reverse(res.begin(),res.end());
        res = next_smaller_element(res);
        reverse(res.begin(),res.end());
        int n = res.size();
        for(int i = 0; i < n; i++){
            res[i] = n-res[i]-1;
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = next_smaller_element(heights);
        vector<int>prev = previous_smaller_element(heights);
        int sz = heights.size();
        int maxArea = 0;
        
        for(int i = 0; i < sz; i++){
            int left = prev[i]+1;
            int right = next[i]-1;
            int area = heights[i] * (right-left+1);
            maxArea = max(area,maxArea);
        }
        
        return maxArea;
    }
};

/*
A LONG FORM summary for LeetCode 84

GOAL:  
Get the maximum area of ANY viable rectangle in the histogram

BRUTE FORCE APPROACH:
The brute force method is rudimentary.  We use left and right indices,
find the MINIMUM of the heights contained within them, and the get the
area by multiplying length (right-left+1) by the height(minimum of heights)
This is O(N^3)

DISMISSING OTHER APPROACHES:
-PrefixSum, or CumSum, is woeful when we do any kind of minimization.  It's clear
we need to minimize among the heights at some point, so Prefix Sum is OUT
-Sliding Windows are an issue; the increasing width of a window isn't viable here
-2 Pointers are out.  If we shrink the MIN side, then we won't be able to build on the optimal solution

THE RIGHT APPROACH (AD-HOC):
At any given index, i, we want the biggest rectangle containing height[i]!

a)  We want the height, which is height[i]
b)  We want the first position BEFORE i that is SMALLER than height[i]
c)  We want the first position AFTER i that is SMALLER than height[i]
2 and 3 give us the LENGTH of our rectangle.  The height is height[i]  :)

e.g. for this array {4,7,5,9,5,8,2,1}
At index i = 2 (value 5)
a) is 5
b) is i = 0  (Position 0.  4 is the first value BEFORE i where the height is less than height[i])
c) is i = 6  (Position 6.  2 is the first value AFTER i where the height is less than height[i])

To get c (the NEXT smaller element for each position), 
we use a variation on Next Greater Element's stack approach, simply next_smaller_element!
To get b (the previous smaller element for each position), we need to modify things a little
i) Make a copy of the heights vector
ii)  Reverse it
iii)  Run the next_smaller_element function on it!
iv) Reverse that result
v)  Using result[i] =  n-result[i]-1, ensure the indices are indeed showing the PREVIOUS smaller element
vi)  Return the vector

So, our main solution will find 2 vectors:
1)  vector<int>next (for the NEXT SMALLER ELEMENT)
2)  vector<int>prev (for the PREVIOUS SMALLER ELEMENT)
3)  We iterate through our heights, and calculate an INITIAL AREA for a rectangle at height[i]
4)  We maximize among these areas to get our result, returning (in my exemplar case) maxArea
*/
