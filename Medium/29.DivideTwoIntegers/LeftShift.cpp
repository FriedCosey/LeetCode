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
        long int counter = 1, tmp = divis;
        while(divid > tmp){
            counter = counter << 1;
            tmp = tmp << 1;
            /*if(divid > tmp && tmp >= (INT_MAX >> 1)){ // OverFlow
                long int diff = divid - tmp;
                while((diff -= divis) >= 0){
                    counter++;
                    if(counter == INT_MAX - 1 && diff - divis >= 0){
                        return sign ? INT_MIN : INT_MAX;
                    }
                }
                if(sign)
                    counter -= counter + counter;
                return counter;
            }*/
                
        }
        //cout << tmp << endl;
        while(tmp > divid){
            counter--;
            tmp -= divis;
        }
        if(counter >= INT_MAX)
            return sign ? INT_MIN : INT_MAX;
        // check sign
        if(sign)
            counter -= counter + counter;
        return counter;
    }
};
