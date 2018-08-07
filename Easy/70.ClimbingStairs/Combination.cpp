// Fail at n = 44
class Solution {
public:
    int climbStairs(int n) {
        int twos = n / 2;
        long int ways = 0;
        for(int i = twos; i >= 0; i--){
            int ones = n - (i * 2);
            double counter = 1;
            int up = ones > i ? i : ones;
            for(int j = 1; j <= up; j++)
                counter = counter / j * (ones + i - j + 1);
            ways += counter;
        }
        return ways;
    }
};
