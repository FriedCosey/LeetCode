class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long int start = 1;
        
        while(start * start < num){
            start = start * 2;
            if(start * start == num)
                return true;
        }
        
        long int end = start;
        start = start / 2;
        
        while(start <= end){
            long int mid = start + (end - start) / 2;
            if(mid * mid > num){
                end = mid - 1;
            }
            else if(mid * mid < num){
                start = mid + 1;
            }
            else{
                return true;
            }
        }
        
        return false;
        
    }
};
