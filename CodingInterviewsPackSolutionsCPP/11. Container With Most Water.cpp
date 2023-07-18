/*
The BF solution is very simple, but will TLE
The approach is clearly about using 2 pointers, because
Prefix/CumSum needs a minimum among the boundaries (not okay here)
Sliding windows depend only on boundaries, and not at all on the body

Key to the 2-pointers approach is to move from
the side with the LOWER value!  (Start from far-left and far-right) :)

O(N) in time
O(1) in memory
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        while(left<right){
            area=max(area, (min(height[left],height[right])*(right-left)));
            
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};