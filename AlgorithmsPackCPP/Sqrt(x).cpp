class Solution {
public:
    double dubs(int x, double EPS = 1e-9){
        double start = 0.0;
        double end = x;
        while(end-start>EPS){
            double mid = start+(end-start)/2.0;
            if(mid*mid-x<0.0)
                start = mid;
            else
                end = mid;
        }
        return start+EPS;
    }

    int mySqrt(int x) {
        return dubs(x);
    }
};
