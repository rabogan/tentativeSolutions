class Solution {
public:
    double fastPow(double x, long long n){
        if(n==0)
            return 1.0;
        double result = fastPow(x,n/2);
        result*=result;
        if(n%2!=0)
            result*=x;
        return result;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        return fastPow(x,N);
    }
};