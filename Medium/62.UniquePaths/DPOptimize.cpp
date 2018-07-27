class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n)
            return uniquePaths(n, m);
        int *cur = new int [m];
        //int *pre = new int [m];
        for(int i = 0; i < m; i++)
            cur[i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                cur[j] = cur[j-1] + cur[j];
            }
            //pre = cur;
        }
        return cur[m-1];
    }
};
