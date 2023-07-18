const int MAX = 10000+1;
int memory[MAX];

class Solution {
public:
    int perfect(int n){
        if(n<=0)
            return 0;
        auto&ret = memory[n];
        if(ret!=-1)
            return ret;
        ret = n;
        for(int i = 1; i < n; i++){
            if(i*i>n)
                break;
            ret = min(ret,1+perfect(n-i*i));
        }
        return ret;
    }

    int numSquares(int n) {
        memset(memory,-1,sizeof(memory));
        return perfect(n);
    }
};