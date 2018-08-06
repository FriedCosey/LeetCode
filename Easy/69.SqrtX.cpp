class Solution {
public:
    int mySqrt(int x) {
        if(!x)
            return x;
        int low = 1, high = x / 2 + 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid <= x / mid &&  (mid + 1) > x / (mid + 1))
                return mid;
            else if(mid > x / mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
};
