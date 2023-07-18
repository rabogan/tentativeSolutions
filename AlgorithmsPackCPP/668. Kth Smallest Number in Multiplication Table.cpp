class Solution {
public:
    int counting(int rows, int cols, int div){
        int count = 0;
        for(int r = 1; r<=rows; r++){
            count+=min(div/r,cols);
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m*n;
        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;
            if(counting(m,n,mid)<k){
                start = mid+1;
            }else{
                end = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};