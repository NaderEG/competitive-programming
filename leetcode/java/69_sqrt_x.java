class Solution {
    public int mySqrt(int x) {
        double mid = Math.floor(x/4);
        double right = Math.floor(x/2);
        double left = 0;
        if(x == 1 || x == 2 || x == 3) {
            return 1;
        }
        while(left < right) {
            
            if(mid*mid > x) {
                right = mid;
            } else if (mid*mid < x) {
                left = mid+1;
            } else {
                return (int)mid;
            }
            mid = Math.floor((right + left) / 2);

        }
        if(mid*mid <= x) {
            return (int)mid;
        }
        return (int)mid-1;
    }
}