class Solution {
public:
    // 51 9 -> 58! / 8!
    int uniquePaths(int m, int n) {
        // (m + n - 2)! / ((m - 1)! * (n - 1)!)
        if(m == 1 || n == 1)
            return 1;
        double res = 1;
        for(int i = 2; i <= n; i++)
            res = res / (i - 1) * (m + i - 2);
        return res;
        
    }
};
