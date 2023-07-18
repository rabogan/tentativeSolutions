class Solution {
    public int mySqrt(int x) {
        double start = 0.0;
        double end = (double) x;
        double EPS = 1e-9;
        while (end - start > EPS) {
            double mid = start + (end - start) / 2.0;
            if (mid * mid - x < 0.0)
                start = mid;
            else
                end = mid;
        }
        return (int) (start + EPS);
    }
}
