// -1 * n should fail (overflow) when n = INT_MIN, idk why pass

class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        if(n < 0) 
            sign = true, n = -1 * n;
        if(n == 0)
            return 1;
        if(n == 1 && !sign) // prevent -1 case
            return x;
        double tmp = n % 2 ? x * myPow(x, n / 2) * myPow(x, n / 2) : myPow(x, n / 2) * myPow(x, n / 2);
        if(tmp == 0)
            return 0;
        return sign ? 1 / tmp : tmp;
        
    }
};
