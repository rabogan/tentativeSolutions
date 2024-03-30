class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
/*1*/   int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ret;
        
/*2*/   for(int i = 0; i <= n-3; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;

/*3*/       int left = i+1;
            int right = n-1;
            
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
/*4*/           if(!sum){
                    ret.push_back({nums[i],nums[left],nums[right]});
                    
/*5*/               left++;
                    while(left<right &&  nums[left]==nums[left-1])
                        left++;

/*6*/               right--;
                    while(left < right && nums[right]==nums[right+1])
                        right--;
                }
    
/*7*/           else if(sum>0)
                    right--;
                else
                    left++;
            }
        }
/*8*/   return ret;
    }
};
/*
This approach adapts the simpler 2-sum 2-pointers 
(sorted) approach
Hash table approach dealt with in the 4-sum answer :)

1)  Firstly, set up the return value, and sort your array
2)  We're going to loop on each index (up to AND INCLUDING 
size-3...work that out)
2b) BUT...to avoid duplicate values, we must check with 
(i>0 && nums[i]==nums[i-1])
3)  If that's clear, We then apply a slightly more 
sophisticated version of the 2-sum
4)  If our sum==0, then we'll need to process things...
but don't forget to add the values to your result!
5)  Increment left as usual...and make sure neighbours 
are not duplicates...if so, increment left again
6)  Decrement right...if neighbours are duplicates, 
decrement right again
7)  Process if sum>0 and sum<0 as usual...
8)  After the loops end, return the result!!
*/
