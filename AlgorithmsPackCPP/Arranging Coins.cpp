class Solution {
public:
    bool possible(int coins, long long row){
        long long sum = (row*(row+1))/2;
        return coins>=sum;
    }
    
    int arrangeCoins(int coins) {
        int start = 0;
        int end = coins;
        int ans = 0;
        while(start<=end){
            int row = start+(end-start)/2;
            if(possible(coins, row)){
                ans = row;
                start=row+1;
            }
            else{
                end = row-1;
            }
        }
        return ans;
    }
};
