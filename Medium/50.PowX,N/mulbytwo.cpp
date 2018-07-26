class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        if(n < 0)
            x = 1 / x;
        if(n == 0)
            return 1;
        if(n == 1) 
            return x;
        return n < 0 ? (n % 2 ? x * myPow((x*x), -(n/2)) : myPow((x*x), -(n/2))) : (n % 2 ? x * myPow((x*x), (n/2)) : myPow((x*x), (n/2)));
        
    }
};
