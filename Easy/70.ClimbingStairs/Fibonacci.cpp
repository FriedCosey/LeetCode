class Solution {
public:
    int climbStairs(int n) {
        int slow = 1, fast = 2, total = 0;
        if(n == 1)
            return slow;
        if(n == 2)
            return fast;
        // 4 = 2 + 3 5 = 3 + 4
        // t = 3 f = 3 s = 2
        for(int i = 3; i <= n; i++){
            total = slow + fast;
            slow = fast;
            fast = total;
        }
        return total;
    }
};
