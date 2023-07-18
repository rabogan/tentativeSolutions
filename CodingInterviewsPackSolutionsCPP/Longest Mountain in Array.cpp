 class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int sz = arr.size();
        int result = 0;
        
        for(int up = 0, down = 0, index = 1; index < sz; index++){
            if(down && arr[index-1]<arr[index]||arr[index-1]==arr[index])
                up = down = 0;
            
            up+=arr[index-1]<arr[index];
            down+=arr[index-1]>arr[index];
            
            if(up&&down)
                result = max(result,up+down+1);
        }
        return result;
    }
};
