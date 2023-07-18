/*
DETAILED SOLUTION (LEFT-TO-RIGHT APPROACH)

THE PROBLEM:
We are given an integer, k
We have a set of points, with the X values like so:
vector<vector<int>>points {{1,3},{2,0},{5,10},{6,-10}};
                            x y
We want to find the MAX value of an equation: yi+yj+|xi-xj|, when |xi-xj|<=k

OBSERVATION:
1) Firstly, because the X values are presorted, the |xi-xj|<=k can be rearranged:
xj - xi <=k  Would be a valid value!  If that's the case, then we can have a look at yi and yj, and calculate a value!
yi+yj+xj-xi

THE BF APPRAOCH:
1) We can use 2 nested loops to try EACH PAIR OF POINTS
2)  Check if the distance is valid (i.e. xj-xi<=k)
3) If the pair of points is valid, compute the equation, maximizing

SLIDING WINDOW:
We will iterate left-to-right, using a sliding window
The window will 'grow', so long as xj-xi<=k
Using a set will allow us to very quickly add the yj and xj values, as long as that xj-xi<=k condition is met
1)  In our window itself:
If a set of coordinates is valid, (i.e. if xj-xi<=k), then we add xj and yj to the set!
We're eventually looking for added points of maximum xj and yj!
while(right<n && ((points[right][0]-points[left][0])<=k))
{                         xj        -      xi        <=k
    mySet.insert({points[right][0]+points[right][1],right});
                         xj       +       yj
    right++;
}
The sliding window is expanded (via right++) to include all valid elements


2)  The equation has been simplified!  That yi+yj+|xi-xj|<=k is yi+yj+xj-xi (if the pair of points is valid)
This becomes yi-xi+(xj+yj)
if(!mySet.empty())  //This means that we have a valid pair of points, remember!!!!

yi+yj+xj-xi
(or, rearranged:  yi-xi+xj+yj)  
yi-xi+xj+yj
The xj+yj comes from the set,
the yi is the points[left][0]; the xi is the points[left][0]
int curMax = points[left[0]]-points[left][1]+mySet.rbegin()->first;

3)  We have to remove the 'left' from the set, if that's what we have!
if(!mySet.empty())
   mySet.erase({mySet.find(points[left][0]+points[left][1]),left}); 
   Basically, that loses   NOT    
   It actually removes the 'old' yi and yj, which are now xi and xj
   
QUICK GUIDE:

x = [0]
y = [1]
i = left
j = right

xi = [left][0]
xj = [right][0]
yi = [left][1]
yj = [right][1]
*/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int left = 0;
        int right = 1;
        int mx = INT_MIN;
        set<pair<int,int>>mySet;
        
        while(left<n){
            if(!mySet.empty())
                mySet.erase(mySet.find({points[left][0]+points[left][1],left}));  //Removed the 'old' xj and yj, which are now xi and xj
                                
            while(right < n && (points[right][0]-points[left][0]<=k)){  //xj-xi<=k
                mySet.insert({points[right][0]+points[right][1],right});  //yi + yj
                right++; //Expands the window
            }
            
            if(!mySet.empty()){
                int curMax = points[left][1]-points[left][0] + mySet.rbegin()->first;   //yi-xi+xj+yj
                mx = max(mx,curMax);
            }
            left++;
            right = max(right,left+1);
        }
        return mx;        
    }
};
