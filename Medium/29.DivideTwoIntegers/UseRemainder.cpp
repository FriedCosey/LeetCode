class Solution {
public:
    int divide(int dividend, int divisor) {
        long int divid = dividend, divis = divisor;
        bool sign = false;
        sign = divisor < 0 ^ dividend < 0 ? true : false;
        // need long int to make -2^31 positive
        if(divis < 0)
            divis -= divis + divis;
        if(divid < 0)
            divid -= divid + divid;
        // record sign and change everything positive
        long int tmp = divis, res = 0, counter = 1;
        while(divid >= divis){
            counter = 1, tmp = divis;
            while(divid > (tmp << 1)){
                counter = counter << 1;
                tmp = tmp << 1;
            }
            divid -= tmp;
            res += counter;
             
        }
        if(res >= INT_MAX)
            return sign ? INT_MIN : INT_MAX;
        // check sign
        if(sign)
            res -= res + res;
        return res;
    }
};
