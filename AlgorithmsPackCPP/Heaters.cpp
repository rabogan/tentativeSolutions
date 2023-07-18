class Solution {
public:
    bool possible(vector<int>&houses, vector<int>&heaters, int radius){
        int j = 0;
        int sz = heaters.size();
        for(int i = 0; i < sz; i++){
            int leftC = heaters[i]-radius;
            int rightC = heaters[i]+radius;
            
            while(j < houses.size() && leftC<=houses[j] && houses[j]<=rightC)
                j++;
        }
        return j==houses.size();
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int start = 0;
        int end = 1e9;
        int ans = end;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(possible(houses,heaters,mid)){
                end = mid-1;
                ans = mid;
            }else
                start = mid+1;
        }
        return ans;
    }
};
