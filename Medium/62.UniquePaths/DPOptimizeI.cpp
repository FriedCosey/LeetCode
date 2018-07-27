class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)
            return uniquePaths(n, m);
        int *cur = new int [m];
        int *pre = new int [m];
        for(int i = 0; i < m; i++)
            cur[i] = pre[i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                cur[j] = cur[j-1] + pre[j];
            }
            pre = cur;
        }
        return pre[m-1];
    }
};
